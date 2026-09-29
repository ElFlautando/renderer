add_subdirectory(renderer)

add_executable(renderer main.cpp)
target_compile_features(renderer PRIVATE cxx_std_23)
target_compile_options(renderer PRIVATE -fno-rtti -fno-exceptions)
target_link_libraries(renderer PRIVATE renderer::core spdlog::spdlog)


