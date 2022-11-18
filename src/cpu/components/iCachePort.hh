#pragma once

#include "common/common.hh"
#include "timing/TimeBuffer.hh"
#include "memory/BaseDram.hh"
#include "cpu/pipeline/PipelineData.hh"

namespace Sim::CPU
{
    class iCachePort
    {
        Memory::BaseDramPtr m_dram; // May change to BaseCachePtr later.

        Timing::TimeBuffer<std::pair<std::function<void(Pipeline::MemResponse)>, Pipeline::MemResponse>> m_iCache_resp_latch;
    };
}
