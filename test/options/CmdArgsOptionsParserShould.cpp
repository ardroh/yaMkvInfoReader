#include <gtest/gtest.h>
#include <vector>
#include "../../src/options/CmdArgsOptionsParser.h"

TEST(CmdArgsOptionsParserShould, ParseInputFileName){
    const auto * expectedFileName = "stubFilename.mkv";
    auto args = std::vector<std::string>{
        "some/file",
        "-f",
        expectedFileName
    };
    auto parser = options::CmdArgsOptionsParser(std::move(args));

    auto receivedOpts = parser.Parse();

    EXPECT_TRUE(receivedOpts.has_value());
    EXPECT_EQ(expectedFileName, receivedOpts.value().InputFilePath);
}