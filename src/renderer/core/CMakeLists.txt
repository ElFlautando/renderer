add_library(renderer_core)
target_sources(
    renderer_core
    PRIVATE Breseham.cpp Mesh.cpp Loader.cpp
    PUBLIC
        FILE_SET publicHeaders
            TYPE HEADERS
            BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}
            FILES Breseham.hpp Mesh.hpp PrimitiveGeometry.hpp Loader.hpp
)

target_link_libraries(
    renderer_core
    PUBLIC spdlog::spdlog
)

add_library(renderer::core ALIAS renderer_core)
