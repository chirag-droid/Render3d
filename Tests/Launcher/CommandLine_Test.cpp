// SPDX-License-Identifier: GPL-3.0-or-later
/*
 * Copyright (C) 2024 Chirag Singla
 */

#include <gtest/gtest.h>

#include "Launcher/CommandLine.cpp"

TEST(LauncherTest, ErrorOnNoArg) {
    std::string executable = "GTest";
    std::string fileName;

    char **argv = new char *[1];
    argv[0] = new char[executable.size() + 1];
    strcpy(argv[0], executable.data());

    EXPECT_EQ(Render3D::Status::Exit, Render3D::CommandLine::Parse(1, argv, fileName));
    EXPECT_EQ(fileName, "");

    delete[] argv[0];
    delete[] argv;
}
