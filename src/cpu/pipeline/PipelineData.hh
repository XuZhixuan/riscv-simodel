#pragma once

#include "common/common.hh"
#include "cpu/DynInst.hh"

namespace Sim::CPU::Pipeline
{
    /**
     * @brief Memory transaction identity struct
     */
    struct TransactionId
    {
        // ID of hart making this transaction
        ThreadId hart_id = UINT16_MAX;
        // ID of the transaction
        size_t trans_id = SIZE_T_MAX;
    };

    /**
     * @brief Memory operation code enum
     */
    enum MemOpcode
    {
        Fetch, Load, Store, AMO, Flush, FlushAll, None
    };

    /**
     * @brief Memory request struct
     */
    struct MemRequest
    {
        // Transaction Identifier
        TransactionId trans_id {};
        // Requested address
        Addr addr = UINT64_MAX;
        // Operation code
        MemOpcode opcode = None;
        // Requested length
        uint16_t length = UINT16_MAX;
        // pointer to store data to
        u_char *data = nullptr;
        // masked bytes
        uint64_t byte_mask = 0;
    };

    /**
     * @brief Memory response struct
     */
    struct MemResponse
    {
        // Transaction ID
        TransactionId trans_id;
        // Requested address
        Addr addr = UINT64_MAX;
        // Operation code
        MemOpcode opcode = None;
        // Requested length
        uint16_t length = UINT16_MAX;
        // pointer to store data to
        u_char *data = nullptr;
        // exception info
        Exception exception;
    };

    /**
     * @brief Redirection info between stages
     */
    struct Redirect
    {
        Addr target;
    };

    struct StageAck
    {
        uint64_t taken_inst_count = 0;
    };

    typedef std::vector<DynInstPtr> InstPkg;
} // Sim::CPU
