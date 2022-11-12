#pragma once

#include <string>

#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"

#include "config/config.hh"

namespace Logging {
    typedef std::shared_ptr<spdlog::logger> LoggerPtr;

    /**
     * @brief Logger init function, init logger according to config
     * @param cfg
     * @return LoggerPtr
     */
    LoggerPtr init_logging(Config::JsonConfig &cfg);

    /**
     * @brief Logger init function, init a file logger
     * @param filename
     * @return LoggerPtr
     */
    LoggerPtr _init_logging(const std::string &prefix);

    /**
     * @brief Logger init function, init a console logger
     * @param prefix
     * @return LoggerPtr
     */
    LoggerPtr _init_logging();
}