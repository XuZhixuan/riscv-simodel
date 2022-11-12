#pragma once

#include <cstdint>

namespace Sim {
    typedef uint64_t Addr; // memory address type

    typedef uint32_t Inst; // Instruction data type

    typedef uint8_t IsaReg; // ISA reg name type

    typedef uint16_t PhyReg; // Physical reg name type

    typedef uint32_t Imm; // immediate data type

    typedef uint8_t Xlen; // Arch X length type

    typedef uint64_t Reg; // Reg data type

    typedef uint16_t ThreadId; // Thread ID type
} // namespace Sim