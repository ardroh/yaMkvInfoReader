#ifndef YAMKVINFOREADER_CMDARGSOPTIONSPARSER_H
#define YAMKVINFOREADER_CMDARGSOPTIONSPARSER_H
#include "IOptionsParser.h"

namespace options {
    class CmdArgsOptionsParser : public IOptionsParser {
    public:
        CmdArgsOptionsParser(std::vector<std::string> && args);
        virtual ~CmdArgsOptionsParser() = default;
    public:
        boost::optional<AppOptions> Parse() override;
    private:
        std::vector<std::string> _args;
    };
} //! options


#endif //YAMKVINFOREADER_CMDARGSOPTIONSPARSER_H
