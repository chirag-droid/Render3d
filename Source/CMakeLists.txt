configure_file(config.h.in ${CMAKE_CURRENT_SOURCE_DIR}/config.h)

set(LAUNCHER_SRC
        Launcher/Launcher.cpp
        Launcher/Launcher.h
        Launcher/CommandLine.cpp
        Launcher/CommandLine.h
)
set(APPLICATION_SRC
        Application/Application.cpp
        Application/Application.h
        Application/ApplicationBuilder.h
        Application/ApplicationBuilder.cpp
)
set(CORE_SRC
        Core/Log.h
        Core/Log.cpp
        Core/Base.h
)
set(SCRIPTING_SRC
        Scripting/Environment.cpp
        Scripting/Environment.h
)

add_executable(Render3D ${LAUNCHER_SRC} ${APPLICATION_SRC} ${CORE_SRC} ${SCRIPTING_SRC})

if (${CMAKE_BUILD_TYPE} STREQUAL Debug)
    target_compile_definitions(Render3D PRIVATE R3D_DEV)
endif ()

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

install(TARGETS Render3D DESTINATION bin)
