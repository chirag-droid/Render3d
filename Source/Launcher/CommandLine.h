// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include "Application/Application.h"

#include "config.h"

#include <iostream>
#include <string>

namespace Render3D::CommandLine {
    void PrintHelp(const std::string &executable);

    void PrintVersion();

    Status Parse(int argc, char *argv[], std::string &fileName);
}
