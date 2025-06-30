import re
import os
import subprocess
import argparse
import sys
from typing import Pattern, List
from glob import glob

FUNCTION_PROTOTYPE_REGEX = re.compile(r'\b[a-zA-Z_][a-zA-Z0-9_]*\s+([a-zA-Z_][a-zA-Z0-9_]*)\s*\([^;]*\);')
ASM_FILE_REGEX = re.compile(r'#pragma GLOBAL_ASM\("(.*?)"\)')
NON_COMPLETE_ASM_FILE_REGEX = re.compile(r'#.*?\n#pragma GLOBAL_ASM\("(.*?)"\)')
JAL_REGEX = re.compile(r'jal\s+([a-zA-Z0-9_]+)')
INCLUDE_REGEX = re.compile(r'#include "(.*?)"')

PROJECT_ROOT = os.path.normpath(os.path.join(os.path.dirname(__file__), os.path.pardir))

VERBOSE = True


def main():
    # Set up argument parsing to allow the user to specify required inputs
    parser = argparse.ArgumentParser(description="Process .c files and generate .decomp.c files with m2c output.")
    parser.add_argument("c_file_path", help="Path to the .c file to process.")
    parser.add_argument("--m2c-path", default="../m2c/m2c.py", help="Path to the m2c.py script.")
    parser.add_argument("--m2c-python-bin", default=sys.executable, help="Python interpreter to use for m2c (e.g., python3, python3.9).")
    parser.add_argument("--verbose", default=False, help="Whether the script should print debug messages.", action=argparse.BooleanOptionalAction)
    args = parser.parse_args()

    c_file: str = args.c_file_path

    VERBOSE = args.verbose
    if os.path.exists(c_file) is False:
        print(f"File {c_file} does not exist! Stopping.")
        exit(1)

    # iterate over all .h files and add them to func_include_map
    func_include_map = {}
    include_header_files = glob(f"{PROJECT_ROOT}/include/**/*.h", recursive=True)
    src_header_files = glob(f"{PROJECT_ROOT}/src/**/*.h", recursive=True)
    for header_file in include_header_files:
        funcs = find_elements_in_file_by_regex(header_file, FUNCTION_PROTOTYPE_REGEX)
        include_file_name = header_file.replace(f"{PROJECT_ROOT}/include/", "")
        for func in funcs:
            if VERBOSE:
                print(f"Adding func {func} to map func_include_map with include file name {include_file_name}")
            func_include_map[func] = include_file_name

    for header_file in src_header_files:
        funcs = find_elements_in_file_by_regex(header_file, FUNCTION_PROTOTYPE_REGEX)
        include_file_name = header_file.replace(f"{PROJECT_ROOT}/src/", "")
        for func in funcs:
            if VERBOSE:
                print(f"Adding func {func} to map func_include_map with include file name {include_file_name}")
            func_include_map[func] = include_file_name

    # determine .s files to decomp, skip .s files wrapped in an if(n)def
    asm_files_to_skip = find_elements_in_file_by_regex(c_file, NON_COMPLETE_ASM_FILE_REGEX)
    all_asm_files = find_elements_in_file_by_regex(c_file, ASM_FILE_REGEX)
    asm_files_to_decomp = []

    for asm_file in all_asm_files:
        if asm_file not in asm_files_to_skip:
            if VERBOSE:
                print(f"Adding {asm_file} to the list of functions to decompile")
            asm_files_to_decomp.append(asm_file)

    includes = set()
    for asm_file in asm_files_to_decomp:
        func_name = os.path.basename(os.path.splitext(asm_file)[0])
        jal_calls = find_elements_in_file_by_regex(os.path.join(PROJECT_ROOT, asm_file), JAL_REGEX)
        for jal_call in jal_calls:
            if jal_call in func_include_map:
                include = func_include_map[jal_call]
                includes.add(include)
                if VERBOSE:
                    print(f"[{func_name}] Found {jal_call} in {include}")
            else:
                if VERBOSE:
                    print(f"[{func_name}] Did not find {jal_call} in func_include_map")

    if "overlays" in c_file:
        header_file_name = c_file.replace('.c', '.h')
    else:
        # core1/core2 file
        header_file_name = c_file.replace('src', 'include').replace('.c', '.h')

    header_include_name = header_file_name.replace(PROJECT_ROOT + "/", "").replace("src/", "").replace("include/", "")

    # check if header file exists, create it on the fly if necessary
    if os.path.exists(header_file_name):
        if VERBOSE:
            print(f"Found header file {header_file_name}")
    else:
        if VERBOSE:
            print(f"Could not find header file {header_file_name}. Creating it.")
        define_name = header_include_name.replace("overlays/", "").replace(".c", "").replace("/", "_").upper()
        with open(header_file_name, "w") as f:
            f.write(f"""#ifndef __{define_name}_H__
#define __{define_name}_H__

#include "common.h"

#endif // __{define_name}_H__
""")
        # Open current file, replace common.h include with overlays header (newly created file) import
        file_content = ""
        with open(c_file, "r") as f:
            file_content = f.read()
        if file_content == "":
            if VERBOSE:
                print(f"Failed to read {c_file}, could not replace #include statement")
            return

        file_content = file_content.replace('#include "common.h"', f'#include "{header_file_name.replace(PROJECT_ROOT + "/src/", "").replace(PROJECT_ROOT + "/include/", "")}"')
        with open(c_file, "w") as f:
            f.write(file_content)

    header_includes = find_elements_in_file_by_regex(header_file_name, INCLUDE_REGEX)
    for header_include in header_includes:
        includes.add(header_include)

    c_file_includes = find_elements_in_file_by_regex(c_file, INCLUDE_REGEX)
    # move includes of .c file into .h file
    for c_file_include in c_file_includes:
        # skip adding include to .h file if it is the .h file for the current .c file
        if c_file_include == header_include_name:
            continue

        if c_file_include != header_file_name:
            if VERBOSE:
                print(f"Found include of {c_file_include} in {c_file}, moving to {header_file_name}")
            includes.add(c_file_include)

    includes = list(includes)
    includes.sort()

    # read .h file
    header_file_lines = []
    with open(header_file_name, 'r') as file:
        header_file_lines = file.readlines()

    # remove include lines
    header_file_lines = list(filter(lambda line: line.startswith("#include") is False, header_file_lines))

    # splice includes into lines
    header_file_lines[3:3] = map(lambda line: f"#include \"{line}\"\n", includes)

    # write .h file with new includes
    with open(header_file_name, 'w') as file:
        file.writelines(header_file_lines)

    # remove #includes from .c file
    c_file_lines = []
    with open(c_file, 'r') as file:
        c_file_lines = file.readlines()

    # remove include lines (expect current header)
    c_file_lines = list(filter(lambda line: line == f"#include \"{header_include_name}\"\n" or line.startswith("#include") is False, c_file_lines))

    # write .c file with "new" includes
    with open(c_file, 'w') as file:
        file.writelines(c_file_lines)

    # Run m2ctx
    (exit_code, output) = run_m2ctx(c_file)
    
    if exit_code != 0:
        print(f"m2ctx.py failed with return code {exit_code}.")
        print(f"m2ctx.py output:\n{output}")
        print("Stopping.")
        return

    for asm_file in asm_files_to_decomp:
        (exit_code, output) = run_m2c(asm_file, os.path.join(PROJECT_ROOT, "ctx.c"), args.m2c_path, args.m2c_python_bin)
        func_name = os.path.basename(os.path.splitext(asm_file)[0])
        if exit_code != 0:
            print(f"Failed to decompile {func_name}:\n{output}")
            continue

        if VERBOSE:
            print(f"Successfully decompiled {func_name}:\n")

        try:
            pragma_index = c_file_lines.index(f"#pragma GLOBAL_ASM(\"{asm_file}\")\n")
        except ValueError:
            print(f"Expected to find {asm_file} in {c_file} but did not find it")
            continue
        
        # Replace pragma line with m2c output, wrapped in ifndef NON_EQUIVALENT
        c_file_lines[pragma_index:pragma_index + 1] = f"""#ifndef NON_EQUIVALENT
#pragma GLOBAL_ASM(\"{asm_file}\")
#else
{output}
#endif
"""

    # write .c file with "new" includes
    with open(c_file, 'w') as file:
        file.writelines(c_file_lines)


def find_elements_in_file_by_regex(file_name: str, regex: Pattern[str]) -> List[str]:
    elements = []
    with open(file_name, 'r') as file:
        content = file.read()
        matches = regex.findall(content)
        for match in matches:
            elements.append(match)
    return elements


def run_m2ctx(c_file_path):
    m2ctx_path = "tools/m2ctx.py"
    command = [sys.executable, m2ctx_path, c_file_path]
    result = subprocess.run(command, capture_output=True, text=True)
    return result.returncode, result.stdout.rstrip("\n")


def run_m2c(asm_file, ctx_file_path, m2c_path, python_version):
    command = [
        python_version,
        m2c_path,
        "--indent-switch-contents",
        "-P", "10",
        "--context", ctx_file_path,
        "--target", "mips-ido",
        asm_file
    ]
    if VERBOSE:
        print(f"Running m2c for {asm_file}")
    result = subprocess.run(command, capture_output=True, text=True)
    return result.returncode, result.stdout.rstrip("\n")


if __name__ == "__main__":
    main()
