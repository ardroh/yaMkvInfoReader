#ifndef YAMKVINFOREADER_APPLOGGER_H
#define YAMKVINFOREADER_APPLOGGER_H

#include <vector>
#include <mutex>
#include <memory>
#include "ILogger.h"
#include "ILogWriter.h"

namespace logging {
    class AppLogger final : public ILogger {
    public:
        AppLogger() = default;
        ~AppLogger() = default;
    public:
        void AddWritter(std::shared_ptr<ILogWriter> writter);
        void Log(LogLevel logLevel, const char * format, ...) override;
        void Debug(const char * format, ...) override;
        void Info(const char * format, ...) override;
        void Warn(const char * format, ...) override;
        void Error(const char * format, ...) override;
    private:
        void LogInternal(LogLevel logLevel, const char * format, va_list args);
    private:
        static const unsigned LOG_BUFFER_SIZE = 2048u;
        std::mutex _logBufferMutex;
        char _logBuffer[LOG_BUFFER_SIZE];
        std::vector<std::shared_ptr<ILogWriter>> _writers;
    };
}

#endif //YAMKVINFOREADER_APPLOGGER_H
