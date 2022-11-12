#pragma once

#include <vector>

#include "common/common.hh"
#include "SimObject.hh"
#include "cpu/BaseCPU.hh"

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

    public:
        /**
         * @brief Constructor of Simulation class
         *
         * @param config
         * @param logger
         */
        Simulation(Config::JsonConfig &config, LoggerPtr logger);

        void tick() override{};

        void advance() override{};

        void evaluate() override{};
    };
}
