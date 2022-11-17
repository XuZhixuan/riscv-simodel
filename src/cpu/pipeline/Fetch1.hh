#pragma once

#include "BaseStage.hh"
#include "Factory.hh"

namespace Sim::CPU::Pipeline
{
    class Fetch1 : public BaseStage
    {
    protected:
        const uint16_t m_fetchByteWidth;
        const uint16_t m_iCacheByteWidth;

        Timing::TimeBuffer<Addr> m_pc;
    public:
        Fetch1(const Config::JsonConfig &cfg, BaseCPU &cpu);

        void set_addr(Addr addr);

        MemRequest prepare_mem_request();

        bool send_fetch_request();

        void recv_fetch_response(MemResponse resp);

        void reset() override;

        void tick() override;

        void advance() override;

        void evaluate() override;
    };
} // Pipeline

