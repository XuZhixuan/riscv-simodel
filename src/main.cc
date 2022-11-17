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
void reset_dir()
{
    char cwd[DIR_NAME_BUFF];
    char *token;
    char *last_token;

    getcwd(cwd, DIR_NAME_BUFF);
    spdlog::info("Current Working Directory is: {}.", cwd);

    token = strtok(cwd, "/");
    while (token != nullptr)
    {
        last_token = token;
        token = strtok(nullptr, "/");
    }

    if (strcmp(last_token, "build") == 0)
    {
        spdlog::warn("Last component of CWD is: {}.", last_token);
        spdlog::warn("Changing working directory to upper level '..'");
        chdir("..");
        getcwd(cwd, DIR_NAME_BUFF);
        spdlog::info("Current Working Directory is: {}.", cwd);
    }
}

int main()
{
    reset_dir();
    CL_INFO("Sim Starting ...");

    Config::JsonConfig config = open_config(CONFIG_FILE);
    Logging::LoggerPtr logger = init_logging(config["log"]);
    ELFLoader::ELFFile elf("./tests/bbl-linux", logger);
    Simulation sim(config["sim"], logger, elf);
    sim.reset();

    size_t max_cycles = config["sim"]["max_cycles"];

    for (size_t i = 0; i <= max_cycles; i++)
    {
        if (unlikely(Sim::finished))
        {
            logger->info("Simulation finished at cycle {}.", i);
            goto exit;
        }
        else
        {
            sim.tick();
            continue;
        }
    }

    logger->critical("Simulation terminated, maximum cycles of {:d} exceeded.", max_cycles);

    exit:
    return 0;
}