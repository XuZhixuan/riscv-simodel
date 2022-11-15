#pragma once

#include "common/common.hh"
#include "common/types.hh"
#include "SimObject.hh"
#include "Factory.hh"
#include "memory/BaseDram.hh"
#include "pipeline/BaseStage.hh"

namespace Sim::CPU
{
    namespace Pipeline
    {
        class BaseStage;
        typedef std::shared_ptr<BaseStage> BaseStagePtr;
    }
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

        // Pointer to DRAM, maybe used to direct access, timing access or assigned to submodules
        Memory::BaseDramPtr m_dram;

        std::vector<Pipeline::BaseStagePtr> m_stages;

    public:
        /**
         * @brief Constructor of BaseCPU
         *
         * @param config
         * @param id
         */
        BaseCPU(const Config::JsonConfig &config, id_t id, Memory::BaseDramPtr);

        ~BaseCPU() override;

        void tick() override;

        void advance() override;

        void evaluate() override;
    };

    typedef std::shared_ptr<BaseCPU> CPUPtr;
}
