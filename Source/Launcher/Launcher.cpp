// SPDX-License-Identifier: GPL-3.0-or-later
/*
 * Copyright (C) 2024 Chirag Singla
 */

#include "Core/Base.h"
#include "Application/ApplicationBuilder.h"
#include "Launcher/CommandLine.h"
#include "Core/Log.h"
#include "config.h"

#include <string>

using namespace Render3D;

int main(int argc, char *argv[]) {
    Log::Init();

    std::string filename = "Examples/Dev.lua";

    Status status = CommandLine::Parse(argc, argv, filename);
    if (status == Status::Exit) {
#ifdef R3D_DEV
        R3D_WARN("Defaulting to file: {}", filename);
#else
        return -1;
#endif
    } else if (status == Status::Warn) {
        // Command lines were correct but filename couldn't be parsed
        return 0;
    }

    std::unique_ptr<Application> application = ApplicationBuilder{}
            .withScript(filename)
            .build();

    application->Run();

    return 0;
}
