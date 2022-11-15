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
    public:
        Fetch1(const Config::JsonConfig &cfg, id_t id, BaseCPU &cpu);

        void tick() override;

        void advance() override;

        void evaluate() override;
    };
} // Pipeline

