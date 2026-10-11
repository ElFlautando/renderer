#pragma once
#include <filesystem>

namespace renderer::core
{

    class Mesh;
    class Loader
    {
      public:
        static auto load(const std::filesystem::path& file_path) -> Mesh;

      private:
        static void parse_vertices(std::span<std::string_view> verts_str);
        static void parse_faces(std::span<std::string_view>);
    };
} // namespace renderer::core
