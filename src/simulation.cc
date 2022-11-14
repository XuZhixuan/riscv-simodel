#include "simulation.hh"

namespace Sim
{
    Simulation::Simulation(Config::JsonConfig &config, Logging::LoggerPtr logger, ELFLoader::ELFFile elf)
            : SimObject("Simulator"), elf(std::move(elf))
    {
        SimObject::logger = std::move(logger);

        m_dram = std::dynamic_pointer_cast<Memory::BaseDram, SimObject>(
                Factory::BaseFactory<>::instance().newComponent(config["memory"]["type"], config["memory"], 0)
        );

        this->elf.load(m_dram);

        int cpu_id = 0;
        for (auto &cfg: config["cpu"])
        {
            m_threads.push_back(std::static_pointer_cast<CPU::BaseCPU, SimObject>(
                    Factory::BaseFactory<Memory::BaseDramPtr>::instance().newComponent(cfg["type"], cfg, cpu_id++, m_dram)
            ));
        }
    }
}
