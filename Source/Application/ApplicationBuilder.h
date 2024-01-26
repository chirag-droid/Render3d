// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include "Application/Application.h"

#include <memory>

namespace Render3D {

    class ApplicationBuilder {
    public:
        ApplicationBuilder &title(const std::string &title);

        ApplicationBuilder &width(uint32_t width);

        ApplicationBuilder &height(uint32_t height);

        ApplicationBuilder &withScript(const std::string &script);

        std::unique_ptr<Application> build();

    private:
        ApplicationSpec m_ApplicationSpec;
    };
}
