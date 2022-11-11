#include <unistd.h>
#include <cstring>
#include <cstdio>

#include "common/lprint.hh"
#include "elf/loader.hh"
#include "config/config.hh"
#include "logging/logging.hh"
#include "simulation.hh"

#define DIR_NAME_BUFF 256

using namespace ELFLoader;
using namespace Config;
using namespace Logging;

namespace Simulator
{
    void reset_dir()
    {
        char cwd[DIR_NAME_BUFF];
        char *token;
        char *last_token;

        getcwd(cwd, DIR_NAME_BUFF);
        CL_INFO("Current Working Directory is: ");
        CL_INFO(cwd);

        token = strtok(cwd, "/");
        while (token != NULL) {
            last_token = token;
            token = strtok(NULL, "/");
        }

        if (strcmp(last_token, "build") == 0) {
            CL_WARN("Last component of CWD is:");
            CL_WARN(last_token);
            CL_WARN("Changing working directory to upper level '..'");
            chdir("..");
            getcwd(cwd, DIR_NAME_BUFF);
            CL_INFO("Current Working Directory is: ");
            CL_INFO(cwd);
        }
    }
}

int main()
{   
    CL_INFO("Simulator Starting ...");
    Simulator::reset_dir();

    // ELFFile elf("./tests/bbl-linux");
    JsonConfig cfg("./config/simulation.json");
    LoggerPtr logger = init_logging("./logs/sim");

    return 0;
}
