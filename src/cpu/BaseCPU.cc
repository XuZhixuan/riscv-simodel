#include <utility>

#include "BaseCPU.hh"
#include "pipeline/Fetch1.hh"

namespace Sim::CPU
{
// Use this to register BaseCPU with name "BaseCPU"
    Factory::BaseFactory<Memory::BaseDramPtr>::Register<BaseCPU> BaseCPURegistry("BaseCPU");

    BaseCPU::BaseCPU(const Config::JsonConfig &config, id_t id, Memory::BaseDramPtr dram)
            : SimObject(fmt::format("CPU {:02d}", id)), m_dram(std::move(dram))
    {
        tid = id;
        xlen = config["xlen"];

        for (auto &cfg: config["stages"])
        {
            m_stages.push_back(std::dynamic_pointer_cast<Pipeline::BaseStage>(
                    Factory::BaseFactory<BaseCPU &>::instance().newComponent(cfg["type"], cfg, id, *this)
            ));
        }

        logger->info("Initiated CPU {:02d}", id);
    }

    void BaseCPU::reset()
    {
        reset(0x00000000);
    }

    void BaseCPU::reset(Addr addr)
    {
        logger->info("{} reset to start at {:#010x}", name, addr);
        for (const auto& stg: m_stages)
        {
            stg->reset();
        }
        std::dynamic_pointer_cast<Pipeline::Fetch1>(m_stages[0])->set_addr(addr);
    }

    void BaseCPU::tick()
    {
        evaluate();
        advance();
    }

    void BaseCPU::advance()
    {
        //
    }

    void BaseCPU::evaluate()
    {
        for (const auto& stg: m_stages)
        {
            stg->evaluate();
        }
    }
} // namespace Sim::CPU