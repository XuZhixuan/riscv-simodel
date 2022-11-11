#include "logging/logging.hh"

using Logging::LoggerPtr;

namespace Simulator
{
    void reset_dir();

    /**
     * @brief Basic Simulation Object class containing logger pointer
    */
    class SimObject
    {
    protected:
        /* pointer to global logger */
        LoggerPtr logger;

    public:
        SimObject(const std::string &name);

        virtual void evaulate() = 0;
        virtual void advance() = 0;
    };
}
