#pragma once

#include <array>
#include <span>
#include <utility>
#include <vector>

namespace renderer::core
{

    // TODO : Move to file
    template <typename T>
    using Point3 = std::array<T, 3>;

    using Point3f = Point3<float>;
    using Point3i = Point3<int>;

    struct Triangle
    {
        std::array<Point3f, 3> verts;
    };

    class MeshManager
    {
      public:
        MeshManager() = default;

        explicit MeshManager(std::vector<Point3f>&& verts)
            : verts_{ std::move(verts) } {};

        // TODO : void overwrite_vertices(std::vector<Point3f>&& verts) { verts_ = std::move(verts); }

        auto get_triangle(std::size_t triangle_idx) -> Triangle;
        auto get_vertices() -> std::span<const Point3f> { return verts_; }

      private:
        std::vector<Point3f> verts_;
        std::vector<Point3i> tris_;
        std::vector<std::vector<size_t>> mesh_;
    };
} // namespace renderer::core
