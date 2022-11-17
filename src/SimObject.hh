#pragma once

#include "common/common.hh"
#include "logging/logging.hh"

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
        void do_assert(bool cond, Args &&... args)
        {
            if (!cond)
            {
                logger->error(args...);
                abort();
            }
        }
    };

    typedef std::shared_ptr<SimObject> SimObjectPtr;

} // Sim
