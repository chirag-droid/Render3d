if (${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
    message(FATAL_ERROR
            "CMake generation is not allowed within the source directory!"
            "\n Remove \"${CMAKE_SOURCE_DIR}/CMakeLists.txt\" and try again from another folder, e.g.:"
            "\n "
            "\n rm -rf CMakeCache.txt CMakeFiles"
            "\n mkdir build"
            "\n cd build"
            "\n cmake .."
    )
endif ()

cmake_minimum_required(VERSION 3.13)

if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    message(INFO "CMake build type not specified. Defaulting to Debug")
    set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Choose Release or Debug" FORCE)
endif ()

project(Render3D VERSION 0.0.1 DESCRIPTION "A lua 3d simulation engine.")

set(CMAKE_CXX_STANDARD_REQUIRED 17)
set(CMAKE_CXX_STANDARD 17)

find_package(Vulkan)

# if Vulkan not found prompt the user to install it
if (NOT Vulkan_FOUND)
    message(FATAL_ERROR "Please install Vulkan SDK. https://vulkan.lunarg.com/sdk/home")
endif ()

add_subdirectory(Vendor)
add_subdirectory(Source)

add_subdirectory(Tests)
