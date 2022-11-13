#pragma once

#include "common/common.hh"
#include "common/types.hh"
#include "SimObject.hh"
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

    public:
        /**
         * @brief Constructor of BaseCPU
         *
         * @param config
         * @param id
         */
        BaseCPU(Config::JsonConfig &config, id_t id);

        void tick() override;

        void advance() override;

        void evaluate() override;
    };

    typedef std::shared_ptr<BaseCPU> CPUPtr;
}
