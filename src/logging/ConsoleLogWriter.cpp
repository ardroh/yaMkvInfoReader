#include <iostream>
#include "ConsoleLogWriter.h"

namespace logging {
    void ConsoleLogWriter::WriteLog(const char *logToWrite) {
        std::cout << logToWrite << std::endl;
    }
}
