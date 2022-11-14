#include "BaseCPU.hh"

namespace Sim::CPU
{
// Use this to register BaseCPU with name "BaseCPU"
    Factory::BaseFactory<Memory::BaseDramPtr>::Register<BaseCPU> BaseCPURegistry("BaseCPU");

    BaseCPU::BaseCPU(const Config::JsonConfig &config, id_t id, Memory::BaseDramPtr)
            : SimObject(config.find("name") == config.end() ? "CPU" : config["name"])
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
} // namespace Sim::CPU