#pragma once

#include <cstdint>

namespace Simulator
{
    typedef uint64_t Addr; // memory address type

    typedef uint32_t Inst; // Instruction data type

    typedef uint8_t  IsaReg; // ISA reg name type

    typedef uint16_t PhyReg; // Physical reg name type

    typedef uint32_t Imm; // immidiate data type

    typedef uint64_t Xlen; // Arch Xlen type

    typedef uint64_t Reg; // Reg data type
} // namespace Simulator