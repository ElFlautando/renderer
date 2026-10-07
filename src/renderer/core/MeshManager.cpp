#include "MeshManager.hpp"

namespace renderer::core
{

    auto MeshManager::get_triangle(std::size_t triangle_idx) -> Triangle
    {

        auto tri = Triangle{};

        const auto& verts_idx = tris_[triangle_idx];
        tri.verts = { verts_[verts_idx[0]], verts_[verts_idx[0]], verts_[verts_idx[0]] };

        return tri;
    }

} // namespace renderer::core
