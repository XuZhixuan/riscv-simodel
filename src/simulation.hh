#pragma once

#include <vector>

#include "common/common.hh"
#include "SimObject.hh"
#include "cpu/BaseCPU.hh"
#include "memory/BaseDram.hh"

namespace Sim
{
    /**
     * @brief Simulation Class, containing CPUs & DRAM
     *
     */
    class Simulation : public SimObject
    {
    protected:
        /* Vector of CPUs */
        std::vector<CPU::CPUPtr> m_threads;

        Memory::BaseDramPtr m_dram;

    public:
        /**
         * @brief Constructor of Simulation class
         *
         * @param config
         * @param logger
         */
        Simulation(Config::JsonConfig &config, Logging::LoggerPtr logger);

        void tick() override{};

        void advance() override{};

        void evaluate() override{};
    };
}
