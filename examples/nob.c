#define NOB_IMPLEMENTATION
#define NOB_STRIP_PREFIX
#define NOB_EXPERIMENTAL_DELETE_OLD
#include "nob.h"

#define BUILD_FOLDER "build/"

Cmd cmd = {0};

int main(int argc, char **argv) {
    NOB_GO_REBUILD_URSELF(argc, argv);

    if(!mkdir_if_not_exists(BUILD_FOLDER)) {
        fprintf(stderr, "Failed to create build folder\n");
        return 1;
    }

    cmd_append(&cmd, 
        "cc", 
        "-Wall", "-Wextra", 
        "-I..",
        "-o", BUILD_FOLDER"int_array", 
        "int_array.c");
    if (!cmd_run(&cmd)) return 1;

    cmd_append(&cmd, 
        "cc",
        "-Wall", "-Wextra",
        "-I..",
        "-o", BUILD_FOLDER"logging",
        "logging.c");
    if (!cmd_run(&cmd)) return 1;

}
