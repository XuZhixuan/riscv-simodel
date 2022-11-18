#pragma once

#include "BaseStage.hh"
#include "Factory.hh"

#include "LoopQueue.hh"

namespace Sim::CPU::Pipeline
{
    class Fetch1 : public BaseStage
    {
    protected:
        const uint16_t m_fetch_byte_width;
        const uint16_t m_iCache_align_byte;
        const uint16_t m_iCache_byte_width;
        const

        Timing::TimeBuffer<Addr> m_pc;

        struct Prediction : public Sim::CPU::Prediction {
            bool taken_valid;
            bool target_valid;
        };

        struct InflightFetch {
            bool busy = false;
            bool killed = false;
            Addr addr = 0;
            std::vector<u_char> inst_bytes;
            std::vector<Sim::CPU::Pipeline::Fetch1::Prediction> predictions;
            Exception exception{};

            InflightFetch() = default;
            explicit InflightFetch(uint64_t byte_width) {
                inst_bytes.resize(byte_width);
                predictions.resize(byte_width / 2);
            }
        };

        LoopQueue<InflightFetch> m_inflight_fetches;
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

