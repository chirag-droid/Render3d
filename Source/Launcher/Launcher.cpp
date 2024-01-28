// SPDX-License-Identifier: GPL-3.0-or-later
/*
 * Copyright (C) 2024 Chirag Singla
 */

#include "Core/Base.h"
#include "Launcher/CommandLine.h"
#include "Core/Log.h"
#include "config.h"

#include <string>

using namespace Render3D;

int main(int argc, char *argv[]) {
    Log::Init();

    std::vector<std::string> args;
    args.reserve(argc);
    for (int i = 0; i < argc; i++) {
        args.emplace_back(argv[i]);
    }

#ifdef R3D_DEV
    if (args.size() == 1) {
        std::string filename = "Examples/Dev.lua";
        R3D_WARN("Defaulting to file: {}", filename);
        args.emplace_back(filename);
    }
#endif

    std::string filename;

    Status status = CommandLine::Parse(args, filename);
    if (status == Status::kError) {
        return -1;
    }

    if (status == Status::kWarn) {
        // Command lines were correct but filename couldn't be parsed
        return 0;
    }

    std::unique_ptr<Application> application = std::make_unique<Application>(
            ApplicationSpec{}.withScript(filename)
    );

    application->Run();

    return 0;
}
