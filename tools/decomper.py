import re
import os
import subprocess
import argparse
import sys
from concurrent.futures import ThreadPoolExecutor, as_completed  # Added for parallel execution

def extract_s_file_paths(c_file_path):
    """
    Extracts paths of .s files from the GLOBAL_ASM macros in a .c file.
    """
    s_file_paths = []
    with open(c_file_path, 'r') as file:
        content = file.read()
        # Regex to match the paths inside GLOBAL_ASM macros
        matches = re.findall(r'GLOBAL_ASM\("([^"]+\.s)"\)', content)
        s_file_paths.extend(matches)
    return s_file_paths

def extract_jal_functions(s_file_path):
    """
    Extracts function names following 'jal' instructions in a .s file.
    """
    jal_functions = []
    with open(s_file_path, 'r') as file:
        for line in file:
            # Regex to match the function name after 'jal'
            match = re.search(r'jal\s+([a-zA-Z0-9_]+)', line)
            if match:
                jal_functions.append(match.group(1))
    return jal_functions

def extract_function_prototypes_from_h_files():
    """
    Extracts function prototypes from all .h files in the include directory.
    Returns a dictionary where keys are function names and values are .h file paths (relative to include/).
    """
    function_prototypes = {}
    # Regex to match function prototypes (e.g., "void func_name(args);")
    prototype_regex = re.compile(r'\b[a-zA-Z_][a-zA-Z0-9_]*\s+([a-zA-Z_][a-zA-Z0-9_]*)\s*\([^;]*\);')

    for root, _, files in os.walk("include/"):
        for file in files:
            if file.endswith('.h'):
                h_file_path = os.path.join(root, file)
                with open(h_file_path, 'r') as h_file:
                    content = h_file.read()
                    # Find all function prototypes in the .h file
                    matches = prototype_regex.findall(content)
                    for func in matches:
                        # Store the function and its .h file path (relative to include/)
                        relative_path = os.path.relpath(h_file_path, "include/")
                        function_prototypes[func] = relative_path
    return function_prototypes

def get_corresponding_h_file_path(c_file_path):
    """
    Determines the corresponding .h file path for a given .c file.
    """
    # Convert the .c file path to a relative path (relative to the src directory)
    relative_c_path = os.path.relpath(c_file_path, start="src")
    # Replace the .c extension with .h and prepend the include directory
    h_file_path = os.path.join("include/", relative_c_path.replace(".c", ".h"))
    return h_file_path

def add_includes_to_h_file(h_file_path, includes):
    """
    Adds #include directives to the .h file, avoiding duplicates.
    """
    # Read existing content of the .h file (if it exists)
    existing_includes = set()
    if os.path.exists(h_file_path):
        with open(h_file_path, 'r') as h_file:
            for line in h_file:
                if line.startswith("#include"):
                    existing_includes.add(line.strip())

    # Combine existing includes with new includes
    all_includes = existing_includes.union(includes)

    # Write the updated content to the .h file
    with open(h_file_path, 'w') as h_file:
        for include in sorted(all_includes):
            h_file.write(f"{include}\n")
        h_file.write("\n")

    print(f"Updated .h file: {h_file_path}")

def run_m2ctx(c_file_path):
    """
    Runs the m2ctx.py script to generate/update the context file for the given .c file.
    Uses the same Python interpreter as the current script and assumes m2ctx.py is located at "tools/m2ctx.py".
    """
    m2ctx_path = "tools/m2ctx.py"
    command = [sys.executable, m2ctx_path, c_file_path]
    result = subprocess.run(command, capture_output=True, text=True)
    if result.returncode != 0:
        print(f"Warning: m2ctx.py failed with return code {result.returncode}.")
        print(f"m2ctx.py output:\n{result.stdout}")
    return result.returncode

def run_m2c(s_file_path, ctx_file_path, m2c_path, python_version):
    """
    Runs the m2c.py program on the given .s file and returns its output and return code.
    """
    command = [
        python_version,
        m2c_path,
        "--indent-switch-contents",
        "-P", "10",
        "--context", ctx_file_path,
        "--target", "mips-ido",
        s_file_path
    ]
    print(f"Running m2c for {s_file_path}")
    result = subprocess.run(command, capture_output=True, text=True)
    return s_file_path, (result.stdout, result.returncode)

def run_m2c_parallel(s_file_paths, ctx_file_path, m2c_path, python_version, max_workers=4):
    """
    Runs m2c.py in parallel for multiple .s files using ThreadPoolExecutor.
    Returns a dictionary where keys are .s file paths and values are tuples of (output, return_code).
    """
    results = {}
    with ThreadPoolExecutor(max_workers=max_workers) as executor:
        # Submit tasks to the executor
        future_to_s_file = {
            executor.submit(run_m2c, s_file_path, ctx_file_path, m2c_path, python_version): s_file_path
            for s_file_path in s_file_paths
        }
        # Collect results as they complete
        for future in as_completed(future_to_s_file):
            s_file_path = future_to_s_file[future]
            try:
                s_file_path, (output, return_code) = future.result()
                results[s_file_path] = (output, return_code)
            except Exception as e:
                print(f"Error processing {s_file_path}: {e}")
                results[s_file_path] = (f"Error: {e}", -1)
    return results

def create_decomp_file(c_file_path, ctx_file_path, s_file_paths, m2c_path, python_version):
    """
    Creates a .decomp.c file with m2c output wrapped in #ifdef NONMATCHING blocks.
    If m2c execution fails, the failure comment includes the m2c output.
    """
    decomp_file_path = c_file_path.replace('.c', '.decomp.c')

    # Run m2c in parallel for all .s files
    print("Running m2c in parallel...")
    m2c_results = run_m2c_parallel(s_file_paths, ctx_file_path, m2c_path, python_version)

    with open(c_file_path, 'r') as original_file, open(decomp_file_path, 'w') as decomp_file:
        for line in original_file:
            if line.startswith("#pragma GLOBAL_ASM"):
                # Extract the .s file path from the #pragma line
                match = re.search(r'GLOBAL_ASM\("([^"]+\.s)"\)', line)
                if match:
                    s_file_path = match.group(1)
                    if os.path.exists(s_file_path):
                        # Write the #ifdef NONMATCHING block
                        decomp_file.write("#ifndef NONMATCHING\n")
                        decomp_file.write(line)
                        decomp_file.write("#else\n")
                        # Get the m2c output for this .s file
                        output, return_code = m2c_results.get(s_file_path, ("", -1))
                        if return_code == 0:
                            # If successful, add the m2c output
                            decomp_file.write(output)
                        else:
                            # If failed, add a failure comment with the m2c output
                            decomp_file.write("// Decompilation failed. m2c output:\n")
                            decomp_file.write(f"// {output}\n")
                        decomp_file.write("#endif\n")
                    else:
                        decomp_file.write(line)  # Keep the original #pragma line
                        decomp_file.write(f"// File not found: {s_file_path}\n")
            else:
                decomp_file.write(line)  # Write non-#pragma lines as-is

    print(f"Created decomp file: {decomp_file_path}")


def main():
    # Set up argument parsing to allow the user to specify required inputs
    parser = argparse.ArgumentParser(description="Process .c files and generate .decomp.c files with m2c output.")
    parser.add_argument("c_file_path", help="Path to the .c file to process.")
    parser.add_argument("--m2c-path", default="../m2c/m2c.py", help="Path to the m2c.py script.")
    parser.add_argument("--m2c-python-bin", default=sys.executable, help="Python interpreter to use for m2c (e.g., python3, python3.9).")
    args = parser.parse_args()

    # Step 1: Extract paths to .s files from the .c file using the GLOBAL_ASM macros
    s_file_paths = extract_s_file_paths(args.c_file_path)
    
    # Step 2: Extract function names following 'jal' instructions from each .s file
    all_jal_functions = []
    for s_file_path in s_file_paths:
        if os.path.exists(s_file_path):
            jal_functions = extract_jal_functions(s_file_path)
            all_jal_functions.extend(jal_functions)
        else:
            print(f"Warning: File {s_file_path} not found.")
    
    # Step 3: Extract function prototypes from all .h files in the include directory
    function_prototypes = extract_function_prototypes_from_h_files()
    
    # Step 4: Check which jal functions are defined in the function prototypes
    found_functions = {}
    missing_functions = set()
    for func in all_jal_functions:
        if func in function_prototypes:
            # If the function is found in a .h file, store it with its corresponding .h file path
            found_functions[func] = function_prototypes[func]
        else:
            # If the function is not found, add it to the missing functions set
            missing_functions.add(func)
    
    # Step 5: Print the found functions and their corresponding .h file paths
    print("Found functions in .h files:")
    for func, h_file_path in found_functions.items():
        print(f"{func} (in {h_file_path})")
    
    # Step 6: Print the missing functions (not found in any .h file)
    print("\nMissing functions (not found in any .h file):")
    for func in missing_functions:
        print(func)
    
    # Step 7: Determine the corresponding .h file path for the .c file
    h_file_path = get_corresponding_h_file_path(args.c_file_path)
    
    # Step 8: Prepare #include directives for the found functions' corresponding .h files
    includes = {f'#include "{h_file}"' for h_file in found_functions.values()}
    
    # Step 9: Add the #include directives to the .h file (or create it if it doesn't exist)
    add_includes_to_h_file(h_file_path, includes)
    
    # Step 10: Run m2ctx.py to generate/update the context file
    print("Running m2ctx.py to generate/update the context file...")
    m2ctx_return_code = run_m2ctx(args.c_file_path)
    if m2ctx_return_code != 0:
        print("Warning: m2ctx.py did not complete successfully. Proceeding with decompilation anyway.")

    # Step 11: Create the .decomp.c file with m2c output wrapped in #ifdef NONMATCHING blocks
    create_decomp_file(args.c_file_path, "./ctx.c", s_file_paths, args.m2c_path, args.m2c_python_bin)

if __name__ == "__main__":
    main()