#pragma once
#include <string>
#include <chrono>
#include <vector>
#include "StreamInfo.h"

namespace mkvs {
    struct MkvFileInfo {
        std::string LongFormatName;
        std::chrono::seconds Duration;
        std::vector<StreamInfo> Streams;
    };
} // namespace mkvs   