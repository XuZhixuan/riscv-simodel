#pragma once

#include "common/common.hh"
#include "common/types.hh"
#include "SimObject.hh"
#include "memory/BaseDram.hh"
#include "Factory.hh"

namespace Sim::CPU
{
    /**
     * @brief Processor class
     */
    class BaseCPU : public SimObject
    {
    public:
        // Local thread ID
        ThreadId tid;

        // Arch X-Length
        Xlen xlen;

        // Pointer to DRAM, maybe used to direct access, timing access or assigned to sub modules
        Memory::BaseDramPtr m_dram;

    public:
        /**
         * @brief Constructor of BaseCPU
         *
         * @param config
         * @param id
         */
        BaseCPU(const Config::JsonConfig &config, id_t id, Memory::BaseDramPtr);

        void tick() override;

        void advance() override;

        void evaluate() override;
    };

    typedef std::shared_ptr<BaseCPU> CPUPtr;
}
