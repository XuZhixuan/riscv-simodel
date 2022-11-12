#include <utility>

#include "SimObject.hh"

namespace Sim {
    LoggerPtr SimObject::logger = nullptr;

    SimObject::SimObject(std::string _name)
            : name(std::move(_name)) {
        //
    }
} // Sim