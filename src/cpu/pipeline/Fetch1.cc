#include "Fetch1.hh"

namespace Sim::CPU::Pipeline
{
    Factory::BaseFactory<BaseCPU &>::Register<Fetch1> fetch1Register("Fetch1");

    Fetch1::Fetch1(const Config::JsonConfig &cfg, BaseCPU &cpu)
            : BaseStage("Fetch1", cpu),
              m_fetchByteWidth(cfg["fetch_byte_width"]),
              m_iCacheByteWidth(cfg["fetch_byte_width"]),
              m_pc("PCRegister", 1)
    {
        //
    }

    void Fetch1::set_addr(Addr addr)
    {
        //
    }

    MemRequest Fetch1::prepare_mem_request()
    {
        MemRequest request{
            .trans_id = {m_cpu.tid, 0},
            .addr = m_pc.get_out_port()->get_data(),
            .opcode = MemOpcode::Fetch,
            .length = m_fetchByteWidth
        };

        return request;
    }

    bool Fetch1::send_fetch_request()
    {
        // TODO: track inflight fetches

        bool success = false;

        if (true)
        {

        }

        return success;
    }

    void Fetch1::reset()
    {}

    void Fetch1::tick()
    {}

    void Fetch1::advance()
    {}

    void Fetch1::evaluate()
    {}
}