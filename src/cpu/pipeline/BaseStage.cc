#include "BaseStage.hh"

namespace Sim::CPU
{
    class BaseCPU;

    namespace Pipeline
    {
        Factory::BaseFactory<Latency>::Register<Timing::TimeBuffer<InstPkg>> instPkgTimeBufferRegistry("InstPkgBuffer");
        Factory::BaseFactory<Latency>::Register<Timing::TimeBuffer<StageAck>> stageAckTimeBufferRegistry("StageAckBuffer");
        Factory::BaseFactory<Latency>::Register<Timing::TimeBuffer<Redirect>> RedirectTimeBufferRegistry("RedirectBuffer");
        /**
         * Base Stage class derived from SimObject, containing ref to CPU
         */

        BaseStage::BaseStage(std::string name, BaseCPU &cpu)
                : SimObject(std::move(name)), m_cpu(cpu), id(cpu.tid), m_flush_sync_latch(fmt::format("{} Flush Sync Latch", name), 1)
        {}


        /**
         * @brief virtual advancing function, advance flush latch & check flush signal
         */
        void BaseStage::advance()
        {
            m_flush_sync_latch.advance();
            if (m_flush_sync_latch.get_out_port()->valid) // Flush signal has arrived
            {
                trace("Flush");
            }
        }

        void BaseStage::connect_in_port(const std::shared_ptr<Timing::TimeBuffer<InstPkg>::BasePort> &stage_in)
        {
            m_stage_in = stage_in;
        }

        void BaseStage::connect_out_port(const std::shared_ptr<Timing::TimeBuffer<InstPkg>::BasePort> &stage_out)
        {
            m_stage_out = stage_out;
        }

        void BaseStage::connect_ack_in_port(const std::shared_ptr<Timing::TimeBuffer<StageAck>::BasePort> &stage_ack_in)
        {
            m_stage_ack_in = stage_ack_in;
        }

        void BaseStage::connect_ack_out_port(const std::shared_ptr<Timing::TimeBuffer<StageAck>::BasePort> &stage_ack_out)
        {
            m_stage_ack_out = stage_ack_out;
        }

        void BaseStage::connect_redirect_port(const std::shared_ptr<Timing::TimeBuffer<Redirect>::BasePort> &redirect)
        {
            m_redirect = redirect;
        }
    };
}
