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
        ThreadId hart_id;
        // ID of the transaction
        uint16_t trans_id;
    };

    /**
     * @brief Memory operation code enum
     */
    enum MemOpcode
    {
        Fetch, Load, Store, AMO, Flush, FlushAll
    };

    /**
     * @brief Memory request struct
     */
    struct MemRequest
    {
        // Transaction ID
        TransactionId trans_id;
        // Requested address
        Addr addr;
        // Operation code
        MemOpcode opcode;
        // Requested length
        uint16_t length;
        // pointer to store data to
        u_char *data;
        // masked bytes
        uint64_t byte_mask;
    };

    /**
     * @brief Memory response struct
     */
    struct MemResponse
    {
        // Transaction ID
        TransactionId trans_id;
        // Requested address
        Addr addr;
        // Operation code
        MemOpcode opcode;
        // Requested length
        uint16_t length;
        // pointer to store data to
        u_char *data;
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
        uint64_t taken_inst_count;
    };

    typedef std::vector<DynInstPtr> InstPkg;
} // Sim::CPU
