#pragma once

#include <vector>

#include "common/common.hh"
#include "SimObject.hh"
#include "cpu/BaseCPU.hh"

namespace Sim {
    class Simulation : public SimObject {
    protected:
        std::vector<CPU::CPUPtr> m_threads;
    public:
        Simulation(Config::JsonConfig &config, LoggerPtr logger);

        void tick() override {};

        void advance() override {};

        void evaluate() override {};
    };
}
