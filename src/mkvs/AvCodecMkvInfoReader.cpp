#include "AvCodecMkvInfoReader.h"
#include <memory>
extern "C" {
    #include <libavformat/avformat.h>
}
#include "../logging/ILogger.h"

using namespace logging;

namespace mkvs {
    using namespace std::chrono;
    MkvFileInfo  AvCodecMkvInfoReader::ReadInfo(const std::string & path) {
        AVFormatContext * rawInputCtx = nullptr;
        auto response = avformat_open_input(&rawInputCtx, path.c_str(), nullptr, nullptr);
        if (response < 0) {
            Logger->Error("Failed to open \"%s\". avformat_open_input return code: %d", path.c_str(), response);
            return {};
        }
        auto inputFormatCtx = std::shared_ptr<AVFormatContext>(
            rawInputCtx,
            [](AVFormatContext * ptr) {
                if (ptr != nullptr) {
                    avformat_close_input(&ptr);
                }
            }
        );
        auto fileInfo = MkvFileInfo();
        fileInfo.LongFormatName = inputFormatCtx->iformat->long_name;
        fileInfo.Duration = duration_cast<seconds>(microseconds(inputFormatCtx->duration));
        response = avformat_find_stream_info(inputFormatCtx.get(),  nullptr);
        if (response < 0)
        {
            Logger->Error("Failed to read stream info from \"%s\". avformat_find_stream_info return code: %d", path.c_str(), response);
            return {};
        }
        for (size_t i = 0; i < inputFormatCtx->nb_streams; i++) {
            auto * stream = inputFormatCtx->streams[i];
            auto * codecParams = stream->codecpar;
            auto streamInfo = mkvs::StreamInfo {
                stream->index,
                static_cast<int>(codecParams->codec_id),
                static_cast<int>(codecParams->codec_type)
            };
            fileInfo.Streams.emplace_back(streamInfo);
        }
        return fileInfo;
    }
} //mkvs
