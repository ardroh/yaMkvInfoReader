#ifndef YAMKVINFOREADER_ILOGWRITER_H
#define YAMKVINFOREADER_ILOGWRITER_H
namespace logging {
    class ILogWriter {
    public:
        virtual ~ILogWriter() = default;
    public:
        virtual void WriteLog(const char * logToWrite) = 0;
    };
}
#endif //YAMKVINFOREADER_ILOGWRITER_H
