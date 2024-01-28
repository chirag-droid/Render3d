// SPDX-License-Identifier: GPL-3.0-or-later
/*
 * Copyright (C) 2024 Chirag Singla
 */

#include "Application/ApplicationSpec.h"
#include "Core/Log.h"

#include <string>

namespace Render3D {
    ApplicationSpec &ApplicationSpec::withTitle(const std::string &title) {
        R3D_TRACE("Set title: {}", title);
        Title = title;
        return *this;
    }

    ApplicationSpec &ApplicationSpec::withWidth(uint32_t width) {
        R3D_TRACE("Set width: {}", width);
        Width = width;
        return *this;
    }

    ApplicationSpec &ApplicationSpec::withHeight(uint32_t height) {
        R3D_TRACE("Set height: {}", height);
        Height = height;
        return *this;
    }

    ApplicationSpec &ApplicationSpec::withScript(const std::string &script) {
        R3D_TRACE("Set script: {}", script);
        Script = script;
        return *this;
    }
}
