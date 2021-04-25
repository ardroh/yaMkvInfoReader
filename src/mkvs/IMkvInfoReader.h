#pragma once
#include "MkvFileInfo.h"
#include <string>

namespace mkvs {
    class IMkvInfoReader {
    public:
        virtual ~IMkvInfoReader() = default;
    public:
        virtual MkvFileInfo ReadInfo(const std::string & path) = 0;
    };
} // namespace mkvs
