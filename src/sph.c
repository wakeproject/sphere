#include "sph.h"

int main(int argc, const char **argv)
{
    if (argc < 1) return 1;

    char** nargv = argv + 1;
    if (argc < 2) {
        return execv("sph-help", nargv);
    } {
        const char* cmd = argv[1];
        if (strcmp(cmd, "cli") == 0)
            return execv("sph-cli", nargv);
        if (strcmp(cmd, "help") == 0)
            return execv("sph-help", nargv);
        if (strcmp(cmd, "init") == 0)
            return execv("sph-init", nargv);
        if (strcmp(cmd, "part") == 0)
            return execv("sph-part", nargv);
        if (strcmp(cmd, "start") == 0)
            return execv("sph-start", nargv);
        if (strcmp(cmd, "stop") == 0)
            return execv("sph-stop", nargv);
        printf("unsupported command: %s\n", cmd);
    }

    return 1;
}
