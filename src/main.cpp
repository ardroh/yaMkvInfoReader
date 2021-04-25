#include <iostream>
#include <filesystem>
#include <vector>
#include "options/CmdArgsOptionsParser.h"
#include "logging/AppLogger.h"
#include "logging/ConsoleLogWriter.h"
#include "mkvs/AvCodecMkvInfoReader.h"

using namespace logging;

namespace logging {
    std::unique_ptr<ILogger> Logger = std::make_unique<AppLogger>();
}

int main(int argc, char** argv) {
    Logger->AddWritter(std::make_shared<ConsoleLogWriter>());
    Logger->Log(LogLevel::INFO, "yetAnotherMkvInfoReader starting");
    auto args = std::vector<std::string>(argv, argv+argc);
    auto parser = options::CmdArgsOptionsParser(std::move(args));
    auto options = parser.Parse();
    if (!options.has_value())
    {
        Logger->Log(LogLevel::INFO, "Failed to parse options!");
        return -1;
    }
    if (!std::filesystem::exists(options.value().InputFilePath)) {
        Logger->Log(LogLevel::INFO, "File \"%s\" doesn't exist!", options.value().InputFilePath.c_str());
        return -1;
    }
    Logger->Log(LogLevel::INFO, "Filename: %s", options.value().InputFilePath.c_str());
    const auto fileSize = std::filesystem::file_size(options.value().InputFilePath);
    Logger->Log(LogLevel::INFO, "File size: %lu bytes", fileSize);
    auto mkvInfoReader = mkvs::AvCodecMkvInfoReader();
    auto fileInfo = mkvInfoReader.ReadInfo(options.value().InputFilePath);
    Logger->Info("Format name: %s", fileInfo.LongFormatName.c_str());
    Logger->Info("Duration: %ds", fileInfo.Duration);
    Logger->Info("Number of streams: %d", fileInfo.Streams.size());
    Logger->Info("Streams:");
    for (size_t i = 0; i < fileInfo.Streams.size(); i++) {
        auto streamInfo = fileInfo.Streams[i];
        Logger->Info("\t%d. Index: %d Type: %d Codec Id: %d", i, streamInfo.Index, streamInfo.CodecType, streamInfo.CodecId);
    }
    return 0;
}
