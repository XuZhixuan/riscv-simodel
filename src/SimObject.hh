#pragma once

#include "common/common.hh"

namespace Sim
{
    /**
     * @brief Basic Simulation Object class containing logger pointer
     */
    class SimObject
    {
    protected:
        /* pointer to global logger */
        static Logging::LoggerPtr logger;

        /* name of the sim object */
        std::string name;

    public:
        /**
         * @brief Constructor of SimObject class
         * @param name
         */
        explicit SimObject(std::string name);

        /**
         * Virtual deconstruct is necessary
         */
        virtual ~SimObject() = default;

        virtual void reset() = 0;

        virtual void tick() = 0;

        virtual void evaluate() = 0;

        virtual void advance() = 0;

        template<typename ...Args>
        inline void do_assert(bool cond, fmt::format_string<Args...> fmt, Args &&... args)
        {
            if (!cond)
            {
                std::string content = fmt::format("Cycle {:>5}, ({:^25}) {}", Clock::cur_tick(), name, fmt);
                logger->error(content, std::forward<Args>(args)...);
                abort();
            }
        }

        template<typename ...Args>
        inline void trace(fmt::format_string<Args...> fmt, Args &&... args)
        {
            std::string content = fmt::format("Cycle {:>5}, ({:^25}) {}", Clock::cur_tick(), fmt);
            logger->trace(content, std::forward<Args>(args)...);
        }
    };

    typedef std::shared_ptr<SimObject> SimObjectPtr;

} // Sim
