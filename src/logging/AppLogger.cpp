#include <cstring>
#include <cstdarg>
#include <cstdio>
#include "AppLogger.h"

namespace logging {
    AppLogger::AppLogger(std::vector<std::shared_ptr<ILogWriter>> && aWriters)
            : _writers(std::move(aWriters)) {

    }

    void AppLogger::Log(LogLevel logLevel, const char *format, ...) {
        _logBufferMutex.lock();
        memset(_logBuffer, 0, LOG_BUFFER_SIZE);
        va_list args;
        va_start (args, format);
        vsnprintf(_logBuffer, LOG_BUFFER_SIZE, format, args);
        va_end (args);
        for (auto writer : _writers) {
            if (writer == nullptr) continue;;
            writer->WriteLog(_logBuffer);
        }
        _logBufferMutex.unlock();
    }
}