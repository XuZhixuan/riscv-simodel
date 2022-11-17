#include <sstream>

#include "simulation.hh"

namespace Sim
{
    bool finished = false;

    Simulation::Simulation(Config::JsonConfig &config, Logging::LoggerPtr logger, ELFLoader::ELFFile &elf_)
            : SimObject("Simulator"), elf(elf_)
    {
        SimObject::logger = std::move(logger);

        m_dram = std::dynamic_pointer_cast<Memory::BaseDram, SimObject>(
                Factory::BaseFactory<>::instance().newComponent(config["memory"]["type"], config["memory"], 0)
        );

        elf.load_to(m_dram);
        tohost_addr = elf.get_tohost();
        fromhost_addr = elf.get_fromhost();

        int cpu_id = 0;
        for (auto &cfg: config["cpu"])
        {
            m_threads.push_back(std::static_pointer_cast<CPU::BaseCPU, SimObject>(
                    Factory::BaseFactory<Memory::BaseDramPtr>::instance().newComponent(cfg["type"], cfg, cpu_id++, m_dram)
            ));
        }
    }

    void Simulation::check_tohost()
    {
        tohost = m_dram->readDouble(tohost_addr);
        if (tohost)
        {
            uint64_t exit_code = 0;
            if (tohost & 0b1)
            {
                // Simulation is to exit, check exit code
                exit_code = tohost >> 0b1;
                if (exit_code)
                {
                    logger->error("Simulation terminated with exitcode: {:#x}", exit_code);
                }
                else
                {
                    logger->info("Simulation finished with exitcode: {:#x}", exit_code);
                }
                finished = true;
            }
            else
            {
                // print from 'tohost'
                std::stringstream print_str;
                if (likely(m_dram->readDouble(tohost) == 64))
                {
                    /**
                     * Read args from the magic memory, syscall function example:
                     * 
                     * #define SYS_write 64
                     *
                     *  static uintptr_t syscall(uintptr_t which, uint64_t arg0, uint64_t arg1, uint64_t arg2)
                     * {
                     *     volatile uint64_t magic_mem[8] __attribute__((aligned(64)));
                     *     magic_mem[0] = which;
                     *     magic_mem[1] = arg0;
                     *     magic_mem[2] = arg1; // address offset 16
                     *     magic_mem[3] = arg2; // address offset 24
                     *     __sync_synchronize();
                     *
                     *     tohost = (uintptr_t)magic_mem;
                     *     while (fromhost == 0)
                     *         ;
                     *     fromhost = 0;
                     *
                     *     __sync_synchronize();
                     *     return magic_mem[0];
                     * }
                     * 
                     * void printstr(const char* s)
                     * {
                     *     syscall(SYS_write, 1, (uintptr_t)s, strlen(s));
                     * }
                     *
                     */

                    Addr print_addr = m_dram->readDouble(tohost + 16);
                    Addr print_len = m_dram->readDouble(tohost + 24);

                    for (size_t i = 0; i < print_len; i++)
                        print_str << m_dram->readByte(print_addr + i);
                    
                    // Set fromhost to indicate finished printing, clear tohost
                    m_dram->writeDouble(1, fromhost_addr);
                    m_dram->writeDouble(0, tohost_addr);

                    std::cout << print_str.str() << std::endl;
                }
            }
        }
    }

    void Simulation::reset()
    {
        for (const auto &cpu: m_threads)
        {
            cpu->reset(elf.get_entry());
        }
    }

    void Simulation::tick()
    {
        Sim::Clock::tick();

        for (const auto &thread: m_threads)
        {
            thread->tick();
        }

        check_tohost();
    }
}
