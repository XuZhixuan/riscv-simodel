#include "simulation.hh"

namespace Sim
{
    Simulation::Simulation(Config::JsonConfig &config, Logging::LoggerPtr logger)
        : SimObject("Simulator")
    {
        SimObject::logger = std::move(logger);

        int cpu_id = 0;
        for (auto &cfg : config["cpu"])
        {
            m_threads.push_back(std::static_pointer_cast<CPU::BaseCPU, SimObject>(
                Factory::Factory::instance().newComponent(cfg["type"], cfg, cpu_id)));
        }
    }
}
