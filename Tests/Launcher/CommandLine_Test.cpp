// SPDX-License-Identifier: GPL-3.0-or-later
/*
 * Copyright (C) 2024 Chirag Singla
 */

#include <gtest/gtest.h>

#include "Launcher/CommandLine.cpp"

class ArgumentsTest: public ::testing::TestWithParam<std::string> {
protected:
    void SetUp() override {
        args.emplace_back("Render3D_Test");
        args.emplace_back(GetParam());
    }

    void TearDown() override {
        args.clear();
    }

    std::vector<std::string> args;
};

TEST_P(ArgumentsTest, Parses) {
    std::string filename;
    EXPECT_EQ(Render3D::Status::kWarn, Render3D::CommandLine::Parse(args, filename));
    EXPECT_EQ(filename, "");
}

INSTANTIATE_TEST_SUITE_P(
    Launcher,
    ArgumentsTest,
    ::testing::Values("-v", "--version", "-h", "--help")
);

class FilenameTest: public ::testing::TestWithParam<std::string> {
protected:
    void SetUp() override {
        args.emplace_back("Render3D_Test");
        args.emplace_back(GetParam());
    }

    void TearDown() override {
        args.clear();
    }

    std::vector<std::string> args;
};

TEST_P(FilenameTest, Parses) {
    std::string filename;
    EXPECT_EQ(Render3D::Status::kSuccess, Render3D::CommandLine::Parse(args, filename));
    EXPECT_EQ(filename, GetParam());
}

INSTANTIATE_TEST_SUITE_P(
        Launcher,
        FilenameTest,
        ::testing::Values("Examples/Test.lua")
);
