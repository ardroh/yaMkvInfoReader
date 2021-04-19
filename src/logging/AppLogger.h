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
        explicit AppLogger(std::vector<std::shared_ptr<ILogWriter>> && aWriters);
        ~AppLogger() = default;
    public:
        void Log(LogLevel logLevel, const char * format, ...) override;
    private:
        static const unsigned LOG_BUFFER_SIZE = 2048u;
        std::mutex _logBufferMutex;
        char _logBuffer[LOG_BUFFER_SIZE];
        std::vector<std::shared_ptr<ILogWriter>> _writers;
    };
}

#endif //YAMKVINFOREADER_APPLOGGER_H
