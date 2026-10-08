#pragma once

#include "Mesh.hpp"
#include <cstddef>
#include <span>
#include <utility>
#include <vector>

namespace renderer::core
{

    class MeshManager
    {
      public:
        MeshManager() = default;

        explicit MeshManager(std::vector<Point3f>&& verts, std::vector<Point3i>&& tris)
            : verts_{ std::move(verts) }
            , tris_{ std::move(tris) } {};

        // TODO : void overwrite_vertices(std::vector<Point3f>&& verts) { verts_ = std::move(verts); }

        auto get_triangle(std::size_t triangle_idx) -> Triangle;
        auto get_vertices() -> std::span<const Point3f> { return verts_; }

      private:
        std::vector<Point3f> verts_;
        std::vector<Point3i> tris_;
        std::vector<std::vector<size_t>> mesh_;
    };
} // namespace renderer::core
