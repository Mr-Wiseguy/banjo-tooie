#include <filesystem>
#include <unordered_set>
#include <fstream>

#include "fmt/core.h"
#include "fmt/ostream.h"

#include "tooie_utils.h"

// These entrypoints have an xori instead of an addi after them for some reason.
// Until a reason is found, a fixed list of which entrypoints to do this for will be used
// to determine which instruction to emit during syscall table generation.
// TODO pull this from a file
std::unordered_set<std::string> xori_entrypoints{
    "baattach_entrypoint_0",
    "baattach_entrypoint_4",
    "bababykaz_entrypoint_0",
    "bababykaz_entrypoint_2",
    "babackpack_get_size",
    "babackpack_entrypoint_9",
    "babee_entrypoint_0",
    "baboost_entrypoint_0",
    "baboost_entrypoint_3",
    "babounce_entrypoint_0",
    "babounce_entrypoint_4",
    "bacough_entrypoint_0",
    "bacough_entrypoint_3",
    "bapackctrl_entrypoint_0",
    "bapackctrl_entrypoint_3",
    "babuzz_entrypoint_0",
    "babuzz_entrypoint_2",
    "badrone_entrypoint_0",
    "badronemem_entrypoint_3",
    "baduo_entrypoint_0",
    "baduo_entrypoint_6",
    "badust_entrypoint_0",
    "badust_entrypoint_11",
    "baeggsetup_entrypoint_0",
    "baeggaim_entrypoint_0",
    "baeggaim_entrypoint_2",
    "baeggcursor_entrypoint_0",
    "baeggcursor_entrypoint_5",
    "baeggfire_entrypoint_0",
    "baeggfire_entrypoint_5",
    "baflameline_entrypoint_0",
    "baflamethrower_entrypoint_0",
    "bafpctrl_entrypoint_0",
    "bafpctrl_entrypoint_8",
    "bahold_entrypoint_0",
    "bahold_entrypoint_1",
    "bakaztorpedo_entrypoint_0",
    "bamoveledge_entrypoint_0",
    "bamoveledge_entrypoint_2",
    "bamum_entrypoint_0",
    "bamum_entrypoint_2",
    "bapulse_entrypoint_0",
    "bapulse_entrypoint_3",
    "bareact_entrypoint_0",
    "basetup_entrypoint_4",
    "bashoes_entrypoint_0",
    "bashoes_entrypoint_4",
    "basquash_entrypoint_0",
    "basquash_entrypoint_2",
    "basnowball_entrypoint_0",
    "baspin_entrypoint_0",
    "bastatemem_entrypoint_3",
    "basub_entrypoint_0",
    "baswim_entrypoint_0",
    "batimer_get_size",
    "batranslate_entrypoint_0",
    "batranslate_entrypoint_2",
    "bavan_entrypoint_0",
    "bawandglow_entrypoint_0",
    "bawasher_entrypoint_0",
    "bawobble_entrypoint_0",
    "bainvisible_entrypoint_0",
    "bainvisible_entrypoint_3",
    "badeathmatch_entrypoint_1",
    "cosectionstor_entrypoint_2",
    "gccubeDll_entrypoint_1",
    "gcwater_entrypoint_0",
    "gclightsDll_entrypoint_0",
    "gcmapDll_entrypoint_1",
    "gcgamefix_entrypoint_0",
    "gcgamefix_entrypoint_1",
    "glreflight_entrypoint_0",
    "gleeprom_entrypoint_0",
    "gldbDll_entrypoint_0",
    "gldbDll_entrypoint_1",
    "gldbDll_entrypoint_2",
    "fxsparkle_entrypoint_3",
    "fxstep_entrypoint_1",
    "fxspgold_entrypoint_1",
    "ncbastring_entrypoint_0",
    "ncbaspiral_entrypoint_0",
    "ncbapan_entrypoint_0",
    "ncbaclimb_entrypoint_0",
    "ncbadie_entrypoint_0",
    "ncbadive_entrypoint_0",
    "ncbafly_entrypoint_0",
    "ncbajig_entrypoint_0",
    "ncbaswim_entrypoint_0",
    "ncbafixpos_entrypoint_0",
    "ncbadolly_entrypoint_0",
    "ncbaspline_entrypoint_0",
    "ncbaspline_entrypoint_1",
    "ncba1p_entrypoint_0",
    "ncstart_entrypoint_0",
    "ncbawaypoint_entrypoint_0",
    "ncbapivot_entrypoint_0",
    "ncbatarget_entrypoint_0",
};

int main(int argc, char** argv) {
    if (argc != 2) {
        fmt::print(stderr,
            "Builds the syscall table for Banjo-Tooie.\n"
            "Usage: {} [output asm path]\n", argv[0]);
        return EXIT_SUCCESS;
    }
    
    std::vector<Segment> overlays = read_config("overlays.us.toml");
    
    std::string output_path = std::string{argv[1]} + "/";
    std::filesystem::create_directories(output_path);
        
    std::ofstream overlay_syscalls{output_path + "overlay_syscalls.s"};
    fmt::print(overlay_syscalls, 
        ".include \"macro.inc\"\n"
        "\n"
        ".text\n"
        "\n"
        "dlabel overlay_syscalls\n"
        "    syscall 0\n"
        "    addi $t0, $zero, 0x0\n"
        "\n");
    
    for (size_t overlay_index = 0; overlay_index < overlays.size(); overlay_index++) {
        const auto& ovl = overlays[overlay_index];
            
        for (size_t entrypoint_index = 0; entrypoint_index < ovl.entrypoints.size(); entrypoint_index++) {
            const auto& entrypoint = ovl.entrypoints[entrypoint_index];
            bool xori = xori_entrypoints.contains(entrypoint.name);

            fmt::print(overlay_syscalls,
                "glabel _{0}\n"
                "    syscall {1}\n"
                "    {3} $t0, $zero, 0x{2:X}\n"
                "endlabel _{0}\n"
                "\n",
                entrypoint.name, overlay_index + 1, entrypoint_index * sizeof(uint32_t), xori ? "xori" : "addi");
        }
    }

    fmt::print(overlay_syscalls,
        "dlabel overlay_syscalls_end\n"
        "    syscall {}\n"
        "    addi $t0, $zero, 0x0\n", overlays.size() + 1);
}
