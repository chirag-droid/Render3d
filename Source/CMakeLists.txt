configure_file(config.h.in ${CMAKE_CURRENT_SOURCE_DIR}/config.h)

set(LAUNCHER_SRC
        ${CMAKE_CURRENT_SOURCE_DIR}/Launcher/Launcher.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Launcher/Launcher.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Launcher/CommandLine.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Launcher/CommandLine.h
)
set(APPLICATION_SRC
        ${CMAKE_CURRENT_SOURCE_DIR}/Application/Application.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Application/Application.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Application/ApplicationSpec.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Application/ApplicationSpec.h
)
set(CORE_SRC
        ${CMAKE_CURRENT_SOURCE_DIR}/Core/Log.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Core/Log.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Core/Base.h
)
set(SCRIPTING_SRC
        ${CMAKE_CURRENT_SOURCE_DIR}/Scripting/Environment.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Scripting/Environment.h
)
set(BACKEND_SRC
        ${CMAKE_CURRENT_SOURCE_DIR}/Backend/Vulkan/Vulkan.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Backend/Vulkan/Vulkan.h
)

# Main Executable Program
add_executable(Render3D ${LAUNCHER_SRC} ${APPLICATION_SRC} ${CORE_SRC} ${SCRIPTING_SRC} ${BACKEND_SRC})

# enable VisualStudio Hot Reload feature
if (MSVC)
    target_compile_options(Render3D PRIVATE $<$<CONFIG:Debug>:/ZI>)
    target_link_options(Render3D PRIVATE $<$<CONFIG:Debug>:/INCREMENTAL>)
endif ()

target_include_directories(Render3D PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(Render3D PRIVATE sol glfw spdlog Vulkan::Vulkan)

set(EXAMPLES_BIN_DIR ${CMAKE_CURRENT_BINARY_DIR}/Examples)
set(EXAMPLES_SRC_DIR ${CMAKE_SOURCE_DIR}/Examples)

file(MAKE_DIRECTORY ${EXAMPLES_BIN_DIR})
configure_file(${EXAMPLES_SRC_DIR}/Log.lua ${EXAMPLES_BIN_DIR})
configure_file(${EXAMPLES_SRC_DIR}/Window.lua ${EXAMPLES_BIN_DIR})
configure_file(${EXAMPLES_SRC_DIR}/Dev.lua ${EXAMPLES_BIN_DIR})
