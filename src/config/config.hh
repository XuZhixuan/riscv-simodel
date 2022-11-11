#pragma once

#include <fstream>
#include <string>

#include <nlohmann/json.hpp>

namespace Config
{
    using json = nlohmann::json;
    /**
     * @brief Json Config class, parsing config/xx.config 
     */
    class JsonConfig
    {
    protected:
        std::ifstream conf_file;
        json data;
    public:
        /**
         * @brief Constructor of JsonConfig
         * 
         * @param filename path to config json file
        */
        JsonConfig(const std::string &filename);
    };
}