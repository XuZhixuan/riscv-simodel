#pragma once

#include <vector>

#include "common/common.hh"
#include "elf/loader.hh"
#include "SimObject.hh"
#include "cpu/BaseCPU.hh"
#include "memory/BaseDram.hh"

namespace Sim
{
    // Global simulation finished flag
    extern bool finished;

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

        // ELF instance loaded
        ELFLoader::ELFFile &elf;

        // Address of tohost in elf
        Addr tohost_addr;

        // Data read from tohost
        uint64_t tohost = 0;

        // Address of fromhost in elf
        Addr fromhost_addr;

        // Data write to fromhost
        uint64_t fromhost = 0;

    public:
        /**
         * @brief Constructor of Simulation class
         *
         * @param config
         * @param logger
         * @param elf
         */
        Simulation(Config::JsonConfig &config, Logging::LoggerPtr logger, ELFLoader::ELFFile &elf);

        /**
         * @brief Check if content exits in tohost, to exit or print.
         */
        void check_tohost();

        /**
         * @brief reset the simulation before start running.
         */
        void reset() override;

        /**
         * @brief tick for every hart in this simulation, then check tohost.
         */
        void tick() override;

        void advance() override
        {};

        void evaluate() override
        {};
    };
}
