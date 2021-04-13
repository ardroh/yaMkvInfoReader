#ifndef YAMKVINFOREADER_CMDARGSOPTIONSPARSER_H
#define YAMKVINFOREADER_CMDARGSOPTIONSPARSER_H
#include "IOptionsParser.h"

namespace options {
    class CmdArgsOptionsParser : public IOptionsParser {
    public:
        CmdArgsOptionsParser(int argc, char** argv);
        virtual ~CmdArgsOptionsParser() = default;
    public:
        boost::optional<AppOptions> Parse() override;
    private:
        std::vector<std::string> _args;
    };
} //!Options


#endif //YAMKVINFOREADER_CMDARGSOPTIONSPARSER_H
