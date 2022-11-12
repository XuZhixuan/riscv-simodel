#pragma once

namespace CPU
{

enum 
/* instructions encoding */
#define BRU_JAR 0
#define BRU_JALR 1
#define BRU_BEQ 2
#define BRU_BNE 3
#define BRU_BLT 4
#define BRU_BGE 5
#define BRU_BLTU 6
#define BRU_BGEU 7

#define CSR_CSRRW 0
#define CSR_CSRRS 1
#define CSR_CSRRC 2
#define CSR_CSRR 3
#define CSR_FENCEI 4
#define CSR_ECALL 5
#define CSR_EBREAK 6
#define CSR_MRET 7
#define CSR_SRET 8
#define CSR_FENCE 9

#define CSR_WFI 10
#define SFENCE_VMA 11
#define SINVAL_VMA 12
#define SFENCE_W_INVAL 13
#define SFENCE_INVAL_IR 14

#define HFENCE_VVMA 15
#define HFENCE_GVMA 16
#define HINVAL_VVMA 17
#define HINVAL_GVMA 18

#define LDU_LB 0
#define LDU_LH 1
#define LDU_LW 2
#define LDU_LD 3
#define LDU_LBU 4
#define LDU_LHU 5
#define LDU_LWU 6

#define STU_SB 0
#define STU_SH 1
#define STU_SW 2
#define STU_SD 3

#define ALU_ADD 0
#define ALU_SUB 1
#define ALU_SLL 2
#define ALU_SLT 3
#define ALU_SLTU 4
#define ALU_XOR 5
#define ALU_SRL 6
#define ALU_SRA 7
#define ALU_OR 8
#define ALU_AND 9

#define ALU_ADDW 10
#define ALU_SUBW 11
#define ALU_SLLW 12
#define ALU_SRLW 13
#define ALU_SRAW 14

#define MUL_MUL 0
#define MUL_MULH 1
#define MUL_MULHSU 2
#define MUL_MULHU 3

#define MUL_MULW 4

#define DIV_DIV 0
#define DIV_DIVU 1
#define DIV_REM 2
#define DIV_REMU 3

#define DIV_DIVW 4
#define DIV_DIVUW 5
#define DIV_REMW 6
#define DIV_REMUW 7

    class DynInst
    {
        //
    };
}
