add_subdirectory(lua)
add_subdirectory(sol2)

set_target_properties(lua PROPERTIES FOLDER "Vendor")
set_target_properties(sol PROPERTIES FOLDER "Vendor")

# GLFW
set(GLFW_INSTALL OFF CACHE BOOL "Generate GLFW installation target" FORCE)
add_subdirectory(GLFW)

set_target_properties(glfw PROPERTIES FOLDER "Vendor")

# Spdlog Logging Library
add_subdirectory(spdlog)

set_target_properties(spdlog PROPERTIES FOLDER "Vendor")

# googletest
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(googletest)
