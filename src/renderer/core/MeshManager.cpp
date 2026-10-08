#include "MeshManager.hpp"

namespace renderer::core
{

    auto MeshManager::get_triangle(std::size_t triangle_idx) -> Triangle
    {

        auto tri = Triangle{};

        const auto& verts_idx = tris_[triangle_idx];
        tri.verts = { verts_[verts_idx.x], verts_[verts_idx.y], verts_[verts_idx.z] };

        return tri;
    }

} // namespace renderer::core
