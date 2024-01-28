// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include "Application/ApplicationSpec.h"

#define GLFW_INCLUDE_VULKAN
#include "GLFW/glfw3.h"

namespace Render3D {


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
