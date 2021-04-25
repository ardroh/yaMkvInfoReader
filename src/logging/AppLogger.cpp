#include <cstring>
#include <cstdarg>
#include <cstdio>
#include "AppLogger.h"

namespace logging {
    void AppLogger::AddWritter(std::shared_ptr<ILogWriter> writter) {
        _writers.emplace_back(writter);
    }

    void AppLogger::Log(LogLevel logLevel, const char *format, ...) {
        va_list args;
        va_start (args, format);
        LogInternal(logLevel, format, args);
        va_end (args);
    }

    void AppLogger::Debug(const char * format, ...) {
        va_list args;
        va_start (args, format);
        LogInternal(LogLevel::DEBUG, format, args);
        va_end (args);
    }

    void AppLogger::Info(const char * format, ...) {
        va_list args;
        va_start (args, format);
        LogInternal(LogLevel::INFO, format, args);
        va_end (args);
    }

    void AppLogger::Warn(const char * format, ...) {
        va_list args;
        va_start (args, format);
        LogInternal(LogLevel::WARNING, format, args);
        va_end (args);
    }

    void AppLogger::Error(const char * format, ...) {
        va_list args;
        va_start (args, format);
        LogInternal(LogLevel::ERROR, format, args);
        va_end (args);
    }

    void AppLogger::LogInternal(LogLevel logLevel, const char * format, va_list args) {
        _logBufferMutex.lock();
        memset(_logBuffer, 0, LOG_BUFFER_SIZE);
        vsnprintf(_logBuffer, LOG_BUFFER_SIZE, format, args);
        for (auto writer : _writers) {
            if (writer == nullptr) continue;;
            writer->WriteLog(_logBuffer);
        }
        _logBufferMutex.unlock();
    }
}