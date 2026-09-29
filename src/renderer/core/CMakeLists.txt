add_library(renderer_core)
target_sources(
    renderer_core
    PRIVATE Breseham.cpp
    PUBLIC
        FILE_SET publicHeaders
            TYPE HEADERS
            BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}
            FILES Breseham.hpp 
)

#[[
target_link_libraries(
    fasas_core
    PUBLIC glaze::glaze fmt::fmt cpr::cpr spdlog::spdlog
)
]]

add_library(renderer::core ALIAS renderer_core)
