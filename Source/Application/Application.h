// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#define GLFW_INCLUDE_VULKAN

#include "GLFW/glfw3.h"

#include <string>

namespace Render3D {
    struct ApplicationSpec {
        std::string Title = "Render3D";
        uint32_t Width = 1600;
        uint32_t Height = 900;
        std::string Script;
    };

    class Application {
    public:
        explicit Application(const ApplicationSpec &appSpec);

        static Application &Get() {
            return *s_Instance;
        }

        ~Application();

        void Run();

    private:
        static Application *s_Instance;

        GLFWwindow *m_Window;
    };
} // Render3D
