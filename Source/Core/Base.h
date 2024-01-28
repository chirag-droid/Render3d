// SPDX-License-Identifier: GPL-3.0-or-later
/*
 * Copyright (C) 2024 Chirag Singla
 */

#pragma once

#include "config.h"

#include <string>

#define ENGINE_VERSION ((VERSION_MAJOR << 22U) | (VERSION_MINOR << 12U) | VERSION_PATCH)

#ifndef NDEBUG
    #define R3D_DEV
#endif

namespace Render3D {
    static std::string EngineName = PROJECT_NAME;
    static std::string AppName = "Render3D Simulation";

    enum Status {
        kError,
        kWarn,
        kSuccess,
    };
}
