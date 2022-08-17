#pragma once

#include <logger.hpp>
#include <easylogging++.h>

INITIALIZE_EASYLOGGINGPP

namespace Logging {

class FileLogger : public Logger {
public:
    virtual void writeInfoEntry(std::string_view entry) override {
        LOG(INFO) << entry;
    }
    virtual void writeWarnEntry(std::string_view entry) override {
        LOG(WARNING) << entry;
    }
    virtual void writeErrorEntry(std::string_view entry) override {
        LOG(ERROR) << entry;
    }
};
}