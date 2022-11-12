#include <unistd.h>
#include <cstring>

#include "simulation.hh"

#include "elf/loader.hh"
#include "config/config.hh"
#include "common/lprint.hh"
#include "logging/logging.hh"

using namespace Sim;
using namespace Config;
using namespace Logging;
using namespace ELFLoader;

#define DIR_NAME_BUFF 256
#define CONFIG_FILE "./config/simulation.json"

/**
 * @brief Helper function to reset working dir
 */
void reset_dir() {
    char cwd[DIR_NAME_BUFF];
    char *token;
    char *last_token;

    getcwd(cwd, DIR_NAME_BUFF);
    CL_INFO("Current Working Directory is: ");
    CL_INFO(cwd);

    token = strtok(cwd, "/");
    while (token != nullptr) {
        last_token = token;
        token = strtok(nullptr, "/");
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

int main() {
    reset_dir();
    CL_INFO("Sim Starting ...");

    Config::JsonConfig config = open_config(CONFIG_FILE);
    Logging::LoggerPtr logger = init_logging(config["log"]);
    Simulation sim(config["sim"], logger);

    return 0;
}