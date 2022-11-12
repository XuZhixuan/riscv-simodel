#include <utility>

#include "simulation.hh"

namespace Sim {
    Simulation::Simulation(Config::JsonConfig &config, LoggerPtr logger)
            : SimObject("Simulator") {
        int cpu_id = 0;
        for (auto &cfg: config["cpu"]) {
            m_threads.push_back(std::static_pointer_cast<CPU::BaseCPU, SimObject>(
                    Factory::Factory::instance().newComponent(cfg["type"], cfg, cpu_id)));
        }
        SimObject::logger = std::move(logger);
    }
}
