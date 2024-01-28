// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include <string>
#include <cstdint>

namespace Render3D {
    struct ApplicationSpec {
        std::string Title = "Render3D";
        uint32_t Width = 1600;
        uint32_t Height = 900;
        std::string Script;

        ApplicationSpec &withTitle(const std::string &title);

        ApplicationSpec &withWidth(uint32_t width);

        ApplicationSpec &withHeight(uint32_t height);

        ApplicationSpec &withScript(const std::string &script);
    };
} // Render3D
