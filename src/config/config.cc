#include "common/lprint.hh"
#include "spdlog/spdlog.h"

#include "config.hh"

namespace Config
{
    JsonConfig open_config(const std::string &filename)
    {
        std::ifstream conf_file(filename);
        if (!conf_file.is_open())
        {
            spdlog::error("Failed to open config file: ", filename);
            exit(-1);
        }

        return JsonConfig::parse(conf_file);
    }
}