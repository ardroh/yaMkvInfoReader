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

TEST(CmdArgsOptionsParserShould, NotReturnOptionsWhenEmptyVectorProvided) {
    auto parser = options::CmdArgsOptionsParser(std::move(std::vector<std::string>()));

    auto receivedOpts = parser.Parse();

    EXPECT_EQ(receivedOpts, boost::none);
}

TEST(CmdArgsOptionsParserShould, NotReturnOptionsWhenOnlyFilenameProvided) {
    auto parser = options::CmdArgsOptionsParser(std::move(std::vector<std::string> {
        "some/filename"
    }));

    auto receivedOpts = parser.Parse();

    EXPECT_EQ(receivedOpts, boost::none);
}

TEST(CmdArgsOptionsParserShould, ParseVerbose){
    auto args = std::vector<std::string>{
            "some/file",
            "--verbose"
    };
    auto parser = options::CmdArgsOptionsParser(std::move(args));

    auto receivedOpts = parser.Parse();

    EXPECT_TRUE(receivedOpts.has_value());
    EXPECT_TRUE(receivedOpts.value().Verbose);
}