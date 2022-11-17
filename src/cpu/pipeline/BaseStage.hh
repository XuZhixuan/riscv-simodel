#pragma once

#include <utility>

#include "common/common.hh"

#include "SimObject.hh"
#include "cpu/BaseCPU.hh"

namespace Sim::CPU
{
    class BaseCPU;

    namespace Pipeline
    {
        /**
         * Base Stage class derived from SimObject, containing ref to CPU
         */
        class BaseStage : public SimObject
        {
        protected:
            // ID same with CPU thread id
            id_t id;

            // ref to the owner cpu
            BaseCPU &m_cpu;

        public:
            /**
             * BaseStage constructor
             * @param name module name
             * @param id cpu thread id
             * @param cpu ref to owner cpu
             */
            BaseStage(std::string name, id_t id, BaseCPU &cpu)
                    : SimObject(std::move(name)), m_cpu(cpu), id(id)
            {}

            /**
             * Default deconstruct function
             */
            ~BaseStage() override = default;
        };

        typedef std::shared_ptr<BaseStage> BaseStagePtr;
    }
}