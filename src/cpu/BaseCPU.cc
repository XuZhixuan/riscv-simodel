#include "BaseCPU.hh"

namespace Sim::CPU
{
// Use this to register BaseCPU with name "BaseCPU"
    Factory::BaseFactory<Memory::BaseDramPtr>::Register<BaseCPU> BaseCPURegistry("BaseCPU");

    BaseCPU::BaseCPU(const Config::JsonConfig &config, id_t id, Memory::BaseDramPtr)
            : SimObject(fmt::format("CPU{:2d}", id))
    {
        tid = id;
        xlen = config["xlen"];

        for (auto &cfg: config["stages"])
        {
            m_stages.push_back(std::dynamic_pointer_cast<Pipeline::BaseStage>(
                    Factory::BaseFactory<BaseCPU&>::instance().newComponent(cfg["type"], cfg, id, *this)
            ));
        }

        for (auto &stg: m_stages)
        {
            stg->evaluate();
        }

        logger->info("Initiated CPU");
    }

    BaseCPU::~BaseCPU()
    {
        //
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