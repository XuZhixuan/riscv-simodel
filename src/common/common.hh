#include <memory>
#include <string>
#include <vector>
#include <utility>

#include "types.hh"

#include "config/config.hh"
#include "logging/logging.hh"
#include "timing/Clock.hh"

#define likely(exp) __builtin_expect(!!(exp), true)
#define unlikely(exp) __builtin_expect(!!(exp), false)