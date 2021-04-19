#ifndef YAMKVINFOREADER_CONSOLELOGWRITER_H
#define YAMKVINFOREADER_CONSOLELOGWRITER_H

#include "ILogWriter.h"

namespace logging {
    class ConsoleLogWriter : public ILogWriter {
    public:
        ConsoleLogWriter() = default;

        ~ConsoleLogWriter() = default;

    public:
        void WriteLog(const char *logToWrite) override;
    };
}


#endif //YAMKVINFOREADER_CONSOLELOGWRITER_H
