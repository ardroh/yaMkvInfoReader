#pragma once
#include "IMkvInfoReader.h"

namespace mkvs {
    class AvCodecMkvInfoReader : public IMkvInfoReader {
    public:
        AvCodecMkvInfoReader() = default;
        ~AvCodecMkvInfoReader() = default;
    public:
        MkvFileInfo ReadInfo(const std::string & path) override;
    };
} // namespace mkvs