#include "CmdArgsOptionsParser.h"

namespace options {
    CmdArgsOptionsParser::CmdArgsOptionsParser(std::vector<std::string> && args)
        : _args(std::move(args))
    {
    }

    boost::optional<AppOptions> CmdArgsOptionsParser::Parse() {
        if (_args.size() <= 1) {
            return boost::none;
        }
        auto options = AppOptions();
        for (int i = 0; i < _args.size(); ++i) {
            const auto & currentLine = _args[i];
            if (currentLine == "-f" && i + 1 < _args.size()) {
                options.InputFilePath = _args[++i];
            } else if (currentLine == "--verbose") {
                options.Verbose = true;
            }
        }
        return options;
    }
} //! options
