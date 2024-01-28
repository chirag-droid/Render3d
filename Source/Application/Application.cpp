// SPDX-License-Identifier: GPL-3.0-or-later
/*
 * Copyright (C) 2024 Chirag Singla
 */

#include "Application/ApplicationSpec.h"
#include "Application/Application.h"
#include "Core/Log.h"

#define GLFW_INCLUDE_VULKAN
#include "GLFW/glfw3.h"

namespace Render3D {
    Application *Application::s_Instance = nullptr;

    Application::Application(const ApplicationSpec &appSpec) {
        if (!glfwInit()) {
            R3D_CRITICAL("Failed to initialize GLFW");
            throw std::exception();
        }
        if (!glfwVulkanSupported()) {
            R3D_CRITICAL("GLFW couldn't find Vulkan loader");
            throw std::exception();
        }

        R3D_INFO("GLFW Initialized");

        m_Window = glfwCreateWindow(
                (int) appSpec.Width,
                (int) appSpec.Height,
                appSpec.Title.c_str(),
                nullptr,
                nullptr
        );

        if (!m_Window) {
            R3D_CRITICAL("Failed to create window");
            throw std::exception();
        }

        s_Instance = this;
        R3D_INFO("Window created");
    }

    Application::~Application() {
        if (m_Window) {
            glfwTerminate();
            R3D_INFO("Window terminated");
        }
    }

    void Application::Run() {
        glfwMakeContextCurrent(m_Window);

        while (!glfwWindowShouldClose(m_Window)) {
            glfwSwapBuffers(m_Window);
            glfwPollEvents();
        }
    }
} // Render3D
