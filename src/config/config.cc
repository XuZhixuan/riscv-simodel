#include "common/lprint.hh"
#include "spdlog/spdlog.h"

#include "config.hh"

namespace Config
{
    JsonConfig::JsonConfig(const std::string &filename)
    {
        conf_file.open(filename);
        if (!conf_file.is_open())
        {
            spdlog::error("Failed to open config file: ", filename);
            exit(-1);
        }

        data = data.parse(conf_file);
        spdlog::info("Loaded config file ", filename);
    }
}