#include "cstdint"

#include "BaseDram.hh"

namespace Sim::Memory
{
    Factory::BaseFactory<>::Register<BaseDram> baseDramRegistry("BaseDRAM");

    BaseDram::BaseDram(const Config::JsonConfig &cfg, id_t id) : SimObject("BaseDRAM")
    {
        m_base = cfg["base"];
        m_length = cfg["length"];

        /* Reserve memory space */
        m_raw_mem = new u_char[m_length];
        m_io_mem = new u_char[m_base - m_io_base];
        m_hole_mem = new u_char[m_hole_end - m_base - m_length];
    }

    BaseDram::~BaseDram()
    {
        delete m_raw_mem;
        delete m_io_mem;
        delete m_hole_mem;
    }

    inline bool BaseDram::checkRange(Addr addr, Addr length) const
    {
        return (addr >= m_base) && (addr + length < m_base + m_length);
    }

    u_char *BaseDram::read(u_char *dest, Addr addr, Addr length)
    {
        do_assert(checkRange(addr, length - 1), "Access out of range address : {:#x}:{:#x}", addr, addr + length - 1);
        std::memcpy(dest, m_raw_mem + addr - m_base, length);
        return dest;
    }

    u_char BaseDram::readByte(Addr addr)
    {
        do_assert(checkRange(addr, 0), "Access out of range address : {:#x}", addr);
        return m_raw_mem[addr - m_base];
    }

    uint64_t BaseDram::readDouble(Addr addr)
    {
        do_assert(checkRange(addr, 7), "Access out of range address : {:#x}", addr);
        return *(u_int64_t *) (m_raw_mem + addr - m_base);
    }

    void BaseDram::write(const u_char *data, Addr addr, Addr length)
    {
        do_assert(checkRange(addr, length - 1), "Access out of range address : {:#x} -> {:#x}", addr, addr + length - 1);
        std::memcpy(m_raw_mem + addr - m_base, data, length);
    }

    void BaseDram::write(const u_char *data, Addr addr, Addr length, Addr mask)
    {
        do_assert(checkRange(addr, length - 1), "Access out of range address : {:#x} -> {:#x}", addr, addr + length - 1);
        for (size_t i = 0; i < length; ++i)
        {
            if ((mask >> i) & 1) m_raw_mem[addr - m_base + i] = data[i];
        }
    }

    void BaseDram::writeByte(u_char data, Addr addr)
    {
        do_assert(checkRange(addr, 0), "Access out of range address : {:#x}", addr);
        m_raw_mem[addr] = data;
    }

    void BaseDram::writeDouble(uint64_t data, Addr addr)
    {
        do_assert(checkRange(addr, 7), "Access out of range address : {:#x}", addr);
        std::memcpy(m_raw_mem + addr - m_base, (u_char *) (&data), 8);
    }

}
