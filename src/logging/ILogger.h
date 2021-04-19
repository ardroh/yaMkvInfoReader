#ifndef YAMKVINFOREADER_ILOGGER_H
#define YAMKVINFOREADER_ILOGGER_H
#include "LogLevel.h"

namespace logging {
    class ILogger {
    public:
        virtual ~ILogger() = default;
    public:
        virtual void Log(LogLevel logLevel, const char * format, ...) = 0;
    };
} //!logging

#endif //YAMKVINFOREADER_ILOGGER_H
