#include "SimObject.hh"

namespace Sim
{
    Logging::LoggerPtr SimObject::logger = nullptr;

    SimObject::SimObject(std::string _name)
        : name(std::move(_name))
    {
        //
    }
} // Sim