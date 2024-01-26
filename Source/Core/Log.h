// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#pragma warning(push, 0)

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

#pragma warning(pop)

namespace Render3D {

    class Log {
    public:
        static void Init();

        static std::shared_ptr<spdlog::logger> &GetLogger() { return s_Logger; }

        static std::shared_ptr<spdlog::logger> &GetLuaLogger() { return s_LuaLogger; }

    private:
        static std::shared_ptr<spdlog::logger> s_Logger;
        static std::shared_ptr<spdlog::logger> s_LuaLogger;
    };
} // namespace Render3D

// Log macros
#define R3D_TRACE(...) ::Render3D::Log::GetLogger()->trace(__VA_ARGS__)
#define R3D_INFO(...) ::Render3D::Log::GetLogger()->info(__VA_ARGS__)
#define R3D_WARN(...) ::Render3D::Log::GetLogger()->warn(__VA_ARGS__)
#define R3D_ERROR(...) ::Render3D::Log::GetLogger()->error(__VA_ARGS__)
#define R3D_CRITICAL(...) ::Render3D::Log::GetLogger()->critical(__VA_ARGS__)
