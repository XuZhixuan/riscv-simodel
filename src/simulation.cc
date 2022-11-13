#include "simulation.hh"

namespace Sim
{
    Simulation::Simulation(Config::JsonConfig &config, Logging::LoggerPtr logger)
        : SimObject("Simulator")
    {
        SimObject::logger = std::move(logger);

        m_dram = std::dynamic_pointer_cast<Memory::BaseDram, SimObject>(
            Factory::Factory::instance().newComponent(config["memory"]["type"], config["memory"], 0)
        );

        int cpu_id = 0;
        for (auto &cfg : config["cpu"])
        {
            m_threads.push_back(std::static_pointer_cast<CPU::BaseCPU, SimObject>(
                Factory::Factory::instance().newComponent(cfg["type"], cfg, cpu_id)));
        }
    }
}
