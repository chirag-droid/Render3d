enable_testing()

add_executable(Render3D_Test)

set(LAUNCHER_TEST_SRC
        ${CMAKE_CURRENT_SOURCE_DIR}/Launcher/CommandLine_Test.cpp
)

target_sources(Render3D_Test PRIVATE ${RENDER3D_TEST_SRC})

# Add Root dir Source/ to include paths and also the current path
target_include_directories(Render3D_Test PRIVATE ${CMAKE_SOURCE_DIR}/Source ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(Render3D_Test PRIVATE sol glfw spdlog Vulkan::Vulkan GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(Render3D_Test)
