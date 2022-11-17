#pragma once

#include "common/common.hh"

namespace Sim::CPU
{
    struct Exception
    {
        bool valid;
        Xlen cause;
        Xlen trap_val;
    };

    struct Prediction
    {
        bool taken;
        Addr target;
    };

    class DynInst
    {
    public:
        enum FuncUnitType
        {
            ALU, MUL, DIV, BRU, CSR, LDU, STU, FPU
        };

        enum InstState
        {
            Fetch1, Fetch2, Decode, Dispatch, Issue, ReadOperand, Execute, WriteBack, Commit, Done
        };

        enum RegType
        {
            None, Int, FLP
        };
    protected:
        // Instruction state
        InstState state;

        // PC point to this inst
        Addr pc;

        // tag in re-order buffer
        uint64_t rob_tag;
        // tag in load-store queue
        uint64_t lsq_tag;

        // Function Uint required
        FuncUnitType fu;
        // Sub Operation code
        uint8_t sub_opcode;

        // Is compressed inst or not
        bool compressed;
        // raw compressed inst
        Inst compressed_inst;
        // raw uncompressed inst
        Inst uncompressed_inst;

        // Is control flow instruction ?
        bool control_flow;

        RegType rs1_type;
        RegType rs2_type;
        RegType rd_type;

        // ISA register name of ResourceRegister 1
        IsaReg isa_rs1;
        // ISA register name of ResourceRegister 2
        IsaReg isa_rs2;
        // ISA register name of ResultDestination
        IsaReg isa_rd;

        // Physical register name of ResourceRegister 1
        PhyReg phy_rs1;
        // Physical register name of ResourceRegister 2
        PhyReg phy_rs2;
        // Physical register name of ResultDestination
        PhyReg phy_rd;

        // Operand 1
        Reg operand1;
        // Operand 2
        Reg operand2;
        // result
        Reg result;

        // TODO: ? what is this for ?
        bool bru_mis_predict;
        // TODO: ? what is this for ?
        Addr bru_target;

        // Immediate data
        Imm imm;

        // Exception info related to this inst
        Exception exception;

        // Prediction info about this inst
        Prediction prediction;

    public:

    };

    typedef std::shared_ptr<DynInst> DynInstPtr;
}
