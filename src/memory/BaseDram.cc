#include "BaseDram.hh"

namespace Sim::Memory
{
    Factory::Registry<BaseDram> baseDramRegistry("BaseDRAM");

    BaseDram::BaseDram(Config::JsonConfig &cfg, id_t id) : SimObject("BaseDRAM")
    {
        m_base = cfg["base"];
        m_length = cfg["length"];

        /* Reserve memory space */
        m_raw_mem.reserve(m_length);
        m_io_mem.reserve(m_base - m_io_base);
        m_hole_mem.reserve(m_hole_end - m_base - m_length);
    }

    bool BaseDram::checkRange(Addr addr, Addr length)
    {
        //
    }

    std::vector<char>::iterator BaseDram::read(Addr addr, Addr length)
    {
        // TODO: range check
        return m_raw_mem.begin() + (addr - m_base);
    }

    

}
