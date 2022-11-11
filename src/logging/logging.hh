#pragma once

#include <string>

#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Logging
{
    using LoggerPtr = std::shared_ptr<spdlog::sinks::sink>;

    LoggerPtr init_logging(const std::string &filename);

    LoggerPtr init_loggint();
}