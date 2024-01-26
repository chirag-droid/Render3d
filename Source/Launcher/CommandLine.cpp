// SPDX-License-Identifier: GPL-3.0-or-later
/*
 * Copyright (C) 2024 Chirag Singla
 */

#include "Core/Base.h"
#include "Launcher/CommandLine.h"

#include <cassert>

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

    Status CommandLine::Parse(int argc, char *argv[], std::string &fileName) {
        assert(argc > 0);
        std::string executable = argv[0];

        if (argc < 2) {
            CommandLine::PrintHelp(executable);
            return Status::Exit;
        }

        std::string arg = argv[1];
        if (arg == "-h" || arg == "--help") {
            CommandLine::PrintHelp(executable);
            return Status::Warn;
        }

        if (arg == "-v" || arg == "--version") {
            CommandLine::PrintVersion();
            return Status::Warn;
        }

        fileName = argv[1];
        return Status::Success;
    }
} // Render3D
