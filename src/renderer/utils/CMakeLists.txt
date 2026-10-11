add_library(renderer_utils)
target_sources(
    renderer_utils
    PRIVATE StringUtils.cpp 
    PUBLIC
        FILE_SET publicHeaders
            TYPE HEADERS
            BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}
            FILES StringUtils.hpp 
)

target_link_libraries(
    renderer_utils
    PUBLIC spdlog::spdlog
)

add_library(renderer::utils ALIAS renderer_utils)
