// SPDX-License-Identifier: GPL-3.0-or-later
/*
 * Copyright (C) 2024 Chirag Singla
 */

#include "Core/Log.h"
#include "config.h"

namespace Render3D {
    std::shared_ptr<spdlog::logger> Log::s_Logger;
    std::shared_ptr<spdlog::logger> Log::s_LuaLogger;

    /*
     * This functions initialises and sets up logging.
     */
    void Log::Init() {
        s_Logger = spdlog::stdout_color_mt(PROJECT_NAME);
        s_Logger->set_level(spdlog::level::trace);

        s_LuaLogger = spdlog::stdout_color_mt("LuaClient");
        s_LuaLogger->set_level(spdlog::level::trace);
    }
} // namespace Render3D
