#ifndef YAMKVINFOREADER_ILOGGER_H
#define YAMKVINFOREADER_ILOGGER_H
#include "LogLevel.h"
#include "ILogWriter.h"

namespace logging {
    class ILogger {
    public:
        virtual ~ILogger() = default;
    public:
        virtual void AddWritter(std::shared_ptr<ILogWriter> writter) = 0;
        virtual void Log(LogLevel logLevel, const char * format, ...) = 0;
        virtual void Debug(const char * format, ...) = 0;
        virtual void Info(const char * format, ...) = 0;
        virtual void Warn(const char * format, ...) = 0;
        virtual void Error(const char * format, ...) = 0;
    };

    extern std::unique_ptr<ILogger> Logger;
} //!logging

#endif //YAMKVINFOREADER_ILOGGER_H
