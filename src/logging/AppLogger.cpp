#include <cstring>
#include <cstdarg>
#include <cstdio>
#include "AppLogger.h"

namespace logging {
    void AppLogger::AddWritter(std::shared_ptr<ILogWriter> writter) {
        _writers.emplace_back(writter);
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