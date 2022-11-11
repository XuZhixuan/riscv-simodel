#include <chrono>
#include <sstream>
#include <iomanip>

#include "logging.hh"
#include "common/lprint.hh"

namespace Logging
{
    LoggerPtr init_logging(const std::string &prefix)
    {
        std::stringstream filename;
        std::time_t t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        filename << prefix << std::put_time(std::localtime(&t), "-%F-%T.log");
        CL_INFO("Logs appending to file:");
        CL_INFO( filename.str());
        return std::make_shared<spdlog::sinks::basic_file_sink_mt>(filename.str());
    }

    LoggerPtr init_logging()
    {
        CL_INFO("Logs appending to console");
        return std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    }
}