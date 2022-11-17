#include <chrono>
#include <sstream>
#include <iomanip>

#include "logging.hh"

namespace Logging
{
    LoggerPtr init_logging(Config::JsonConfig &cfg)
    {
        LoggerPtr logger;
        if (cfg["type"] == "file")
        {
            logger = _init_logging(cfg["prefix"]);
        }
        else if (cfg["type"] == "console")
        {
            logger = _init_logging();
        }
        else
        {
            spdlog::error("Unknown logging type: {}", cfg["type"]);
            exit(-1);
        }

        logger->set_level(spdlog::level::trace);
        logger->set_pattern("%^[%l]%$ -> %v");
        logger->info("Logger initiated ...");

        return logger;
    }

    LoggerPtr _init_logging(const std::string &prefix)
    {
        std::stringstream filename;
        std::time_t t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        filename << prefix << std::put_time(std::localtime(&t), "-%F-%T.log");
        spdlog::info("Logs appending to file: {}", filename.str());
        auto sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(filename.str());
        return std::make_shared<spdlog::logger>("SIModel", sink);
    }

    LoggerPtr _init_logging()
    {
        spdlog::info("Logs appending to console");
        auto sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>(spdlog::color_mode::automatic);
        return std::make_shared<spdlog::logger>("SIModel", sink);
    }
}