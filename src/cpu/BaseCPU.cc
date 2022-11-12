#include "BaseCPU.hh"

namespace Sim::CPU
{
    // Use this to register BaseCPU with name "BaseCPU"
    Factory::Registry<BaseCPU> baseCPURegistry("BaseCPU");

    BaseCPU::BaseCPU(Config::JsonConfig &config, id_t id)
        : SimObject(
              config.find("name") == config.end() ? "CPU" : config["name"])
    {
        tid = id;
        xlen = config["xlen"];
        logger->info("Initiated CPU");
    }

    void BaseCPU::tick()
    {
        //
    }

    void BaseCPU::advance()
    {
        //
    }

    void BaseCPU::evaluate()
    {
        //
    }
}