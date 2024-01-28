// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include "Application/Application.h"

#include "config.h"

#include <iostream>
#include <string>
#include <vector>

namespace Render3D::CommandLine {
    void PrintHelp(const std::string &executable);

    void PrintVersion();

    Status Parse(const std::vector<std::string>& args, std::string &fileName);
}
