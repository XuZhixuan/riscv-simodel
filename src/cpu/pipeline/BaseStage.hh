#pragma once

#include <utility>

#include "common/common.hh"

#include "SimObject.hh"
#include "cpu/BaseCPU.hh"

namespace Sim::CPU
{
    class BaseCPU;

    typedef std::shared_ptr<BaseCPU> BaseCPUPtr;

    namespace Pipeline
    {
        class BaseStage : public SimObject
        {
        protected:
            id_t id;

            BaseCPU &m_cpu;

        public:
            BaseStage(std::string name, id_t id, BaseCPU &cpu)
            : SimObject(std::move(name)), m_cpu(cpu), id(id)
            {}

            ~BaseStage() override {}
        };

        typedef std::shared_ptr<BaseStage> BaseStagePtr;
    }
}