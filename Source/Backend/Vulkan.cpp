// SPDX-License-Identifier: GPL-3.0-or-later
/*
 * Copyright (C) 2024 Chirag Singla
 */

#include "Backend/Vulkan.h";
#include "vulkan/vulkan.hpp";

namespace Render3D {
    namespace Utils {
        void GetVideoCapabilities(const vk::PhysicalDevice& physicalDevice, const vk::VideoProfileInfoKHR videoProfile) {
            physicalDevice.getVideoCapabilitiesKHR(videoProfile).;
        };
    }
}