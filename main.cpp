#include <iostream>
#include "options/CmdArgsOptionsParser.h"

int main(int argc, char** argv) {
    auto parser = options::CmdArgsOptionsParser(argc, argv);
    auto options = parser.Parse();
    if (!options.has_value())
    {
        std::cout << "Failed to parse options!" << std::endl;
        return -1;
    }
    std::cout << options.value().InputFilePath << std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
