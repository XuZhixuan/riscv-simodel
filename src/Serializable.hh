#pragma once

#include "nlohmann/json.hpp"

namespace Sim
{
    /**
     * @brief pure virtual class containing serialization interface
     * 
     */
    class Serializable
    {
    public:
        toJson();
    };
} // namespace Sim
