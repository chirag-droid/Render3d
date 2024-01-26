project(sol VERSION 3.3.0)

add_library(sol INTERFACE)
set_target_properties(sol PROPERTIES LINKER_LANGUAGE CXX)
target_sources(sol
    PUBLIC
        include/sol/sol.hpp
        include/sol/config.hpp
        include/sol/forward.hpp
)
target_include_directories(sol INTERFACE include)
target_link_libraries(sol INTERFACE lua)
