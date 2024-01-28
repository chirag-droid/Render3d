// SPDX-License-Identifier: GPL-3.0-or-later
/*
 * Copyright (C) 2024 Chirag Singla
 */

#include "Core/Base.h"
#include "Launcher/CommandLine.h"

#include <vector>
#include <string>

namespace Render3D {
    void CommandLine::PrintHelp(const std::string &executable) {
        std::cout << PROJECT_NAME << " v" << VERSION_MAJOR << "." << VERSION_MINOR << "\n"
                  << "Usage:\n"
                  << "\n"
                  << "  " << executable << " " << "<path-to-file>\n"
                  << "  " << executable << " " << "[options]\n"
                  << "\n"
                  << "Options:\n"
                  << "  -h, --help     Display this help message\n"
                  << "  -v, --version  Display program version\n";
    }

    void CommandLine::PrintVersion() {
        std::cout << "v" << VERSION_MAJOR << "." << VERSION_MINOR << "\n";
    }

    Status CommandLine::Parse(const std::vector<std::string>& args, std::string &fileName) {
        if (args.empty()) {
            return Status::kError;
        }

        if (args.size() == 1) {
            const std::string& executable = args[0];
            CommandLine::PrintHelp(executable);
            return Status::kWarn;
        }

        const std::string& executable = args[0];
        const std::string& argument = args[1];

        if (argument == "-h" || argument == "--help") {
            CommandLine::PrintHelp(executable);
            return Status::kWarn;
        }

        if (argument == "-v" || argument == "--version") {
            CommandLine::PrintVersion();
            return Status::kWarn;
        }

        fileName = argument;
        return Status::kSuccess;
    }
} // Render3D
