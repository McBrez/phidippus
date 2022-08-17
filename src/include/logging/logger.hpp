#pragma once

// Standard includes
#include <memory>
#include <string_view>

namespace Logging {
class Logger {

public:
    virtual ~Logger() = default;
    virtual void writeInfoEntry(std::string_view entry) = 0;
    virtual void writeWarnEntry(std::string_view entry) = 0;
    virtual void writeErrorEntry(std::string_view entry) = 0;
};
}