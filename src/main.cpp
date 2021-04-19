#include <iostream>
#include <filesystem>
#include <vector>
#include "options/CmdArgsOptionsParser.h"
#include "logging/AppLogger.h"
#include "logging/ConsoleLogWriter.h"

using namespace logging;

int main(int argc, char** argv) {
    auto logger = logging::AppLogger(std::move(std::vector<std::shared_ptr<logging::ILogWriter>>{
        std::make_shared<logging::ConsoleLogWriter>()
    }));
    logger.Log(LogLevel::INFO, "yetAnotherMkvInfoReader starting");
    auto args = std::vector<std::string>(argv, argv+argc);
    auto parser = options::CmdArgsOptionsParser(std::move(args));
    auto options = parser.Parse();
    if (!options.has_value())
    {
        logger.Log(LogLevel::INFO, "Failed to parse options!");
        return -1;
    }
    if (!std::filesystem::exists(options.value().InputFilePath)) {
        logger.Log(LogLevel::INFO, "File \"%s\" doesn't exist!", options.value().InputFilePath.c_str());
        return -1;
    }
    logger.Log(LogLevel::INFO, "Filename: %s", options.value().InputFilePath.c_str());
    return 0;
}
