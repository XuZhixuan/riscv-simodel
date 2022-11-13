#pragma once

#include "common/common.hh"
#include "common/types.hh"
#include "SimObject.hh"
#include "Factory.hh"

namespace Sim::Memory
{
    /**
     * @brief Base DRAM class
     */
    class BaseDram : public SimObject
    {
    protected:
        /* base address of dram */
        Addr m_base;

        /* length of dram */
        Addr m_length;

        /* base address of io memory */
        Addr m_io_base = 0x0;

        /* Highest memory address */
        Addr m_hole_end = 0xffffffff;

        /* DRAM raw data */
        std::vector<char> m_raw_mem;

        /* IO memory range */
        std::vector<char> m_io_mem;

        /* Other memory  */
        std::vector<char> m_hole_mem;

    public:
        /**
         * @brief Construct a new BaseDram object
         *
         */
        BaseDram() : SimObject("BaseDRAM") {}

        /**
         * @brief Construct a new BaseDram object accroading to config
         * 
         * @param cfg 
         * @param id 
         */
        BaseDram(Config::JsonConfig &config, id_t id);

        /**
         * @brief Destroy the BaseDram object
         *
         */
        ~BaseDram() {}

        /**
         * @brief SimObject Interface function, unimplemented.
         */
        void tick() override {}

        /**
         * @brief SimObject Interface function, unimplemented.
        */
        void evaluate() override {}

        /**
         * @brief SimObject Interface function, unimplemented.
        */
        void advance() override {}

        bool checkRange(Addr addr, Addr length);

        std::vector<char>::iterator read(Addr addr, Addr length);
    };

    typedef std::shared_ptr<BaseDram> BaseDramPtr;

    
}