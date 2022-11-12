#pragma once

#include <iostream>
#include "spdlog/spdlog.h"

template<typename... T>
void lprint(const T &...items) {
    (std::cout << ... << items);
}

#define CL_TRACE(str...) spdlog::log(spdlog::level::trace, str, '\n')
#define CL_DEBUG(str...) spdlog::log(spdlog::level::debug, str, '\n')
#define CL_INFO(str...) spdlog::log(spdlog::level::info, str, '\n')
#define CL_WARN(str...) spdlog::log(spdlog::level::warn, str, '\n')
#define CL_FAIL(str...) spdlog::log(spdlog::level::err, str, '\n')
#define CL_CRIT(str...) spdlog::log(spdlog::level::critical, str, '\n')