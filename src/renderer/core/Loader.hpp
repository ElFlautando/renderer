#pragma once
#include "PrimitiveGeometry.hpp"
#include <filesystem>
#include <span>
#include <string_view>
#include <vector>

namespace renderer::core
{

    class Mesh;
    class Loader
    {
      public:
        static auto load(const std::filesystem::path& file_path) -> Mesh;

      private:
        static void parse_vertices(std::span<const std::string_view> verts_str, std::vector<Point3f> verts);
        static void parse_faces(std::span<const std::string_view> faces_str,
                                std::vector<std::string_view>& buffer_data);
    };
} // namespace renderer::core
