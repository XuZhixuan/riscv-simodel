#pragma once

#include "logging/logging.hh"

using Logging::LoggerPtr;

namespace Sim {
    /**
      * @brief Basic Simulation Object class containing logger pointer
     */
    class SimObject {
    protected:
        /* pointer to global logger */
        static LoggerPtr logger;

        std::string name;

    public:
        /**
         * @brief Constructor of SimObject
         * @param name
         */
        SimObject(std::string name);

        virtual void tick() = 0;

        virtual void evaluate() = 0;

        virtual void advance() = 0;
    };
    typedef std::shared_ptr<SimObject> SimObjectPtr;

} // Sim

