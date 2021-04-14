#include "CmdArgsOptionsParser.h"

namespace options {
    CmdArgsOptionsParser::CmdArgsOptionsParser(std::vector<std::string> && args)
        : _args(std::move(args))
    {
    }

    boost::optional<AppOptions> CmdArgsOptionsParser::Parse() {
        auto options = AppOptions();
        for (int i = 0; i < _args.size(); ++i) {
            const auto & currentLine = _args[i];
            if (currentLine == "-f" && i + 1 < _args.size()) {
                options.InputFilePath = _args[++i];
            }
        }
        return options;
    }
} //! options
