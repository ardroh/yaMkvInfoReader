#include "CmdArgsOptionsParser.h"

namespace options {
    CmdArgsOptionsParser::CmdArgsOptionsParser(int argc, char **argv) {
        for (int i = 1; i < argc; ++i) {
            _args.push_back(std::string(argv[i]));
        }
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
}
