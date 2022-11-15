#include "Fetch1.hh"

namespace Sim::CPU::Pipeline
{
    Factory::BaseFactory<BaseCPU&>::Register<Fetch1> fetch1Register("Fetch1");

    Fetch1::Fetch1(const Config::JsonConfig &cfg, id_t id, BaseCPU &cpu)
            : BaseStage("Fetch1", id, cpu), m_fetchByteWidth(cfg["fetch_byte_width"]), m_iCacheByteWidth(cfg["fetch_byte_width"])
    {
        //
    }

    void Fetch1::tick()
    {}

    void Fetch1::advance()
    {}

    void Fetch1::evaluate()
    {
        logger->info("Fetch1 {:2d} is evaluated", id);
    }
}