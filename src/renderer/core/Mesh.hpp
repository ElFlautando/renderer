#pragma once

#include "PrimitiveGeometry.hpp"
#include <cstddef>
#include <span>
#include <utility>
#include <vector>

namespace renderer::core
{

    class Mesh
    {
      public:
        Mesh() = default;

        explicit Mesh(std::vector<Point3f>&& verts, std::vector<Point3i>&& tris)
            : verts_{ std::move(verts) }
            , tris_{ std::move(tris) } {};

        auto get_triangle(std::size_t triangle_idx) -> Triangle;
        auto get_vertices() -> std::span<const Point3f> { return verts_; }

      private:
        std::vector<Point3f> verts_;
        std::vector<Point3i> tris_;
    };
} // namespace renderer::core
