#pragma once

#include <fstream>
#include <string>

#include <nlohmann/json.hpp>

namespace Config {
    using JsonConfig = nlohmann::json;

    /**
     * @brief Open config file from filename
     * @param filename
     * @return
     */
    JsonConfig open_config(const std::string &filename);
}