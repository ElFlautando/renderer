
#include "Breseham.hpp"
#include "Mesh.hpp"
#include <ios>
#include <spdlog/spdlog.h>
#include <vector>

#include <fstream>

void save_pgm(const char* filename, const std::vector<std::vector<int>>& pixels)
{
    int width = pixels.size();     // x
    int height = pixels[0].size(); // y

    std::ofstream out(filename, std::ios::binary);

    out << "P5\n"
        << width << " " << height << "\n"
        << "255\n";

    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            auto pixel = static_cast<unsigned char>(pixels[x][y]);
            out.write(reinterpret_cast<const char*>(&pixel), 1);
        }
    }
}

auto main() -> int
{
    auto buffer = std::vector<std::vector<int>>(100, std::vector<int>(100));

    auto mesh_mgr = renderer::core::Mesh({ { 1, 1.5, 4 }, { 4, 2, 1 }, { 2, -3, 2.3 } }, { { 0, 1, 2 } });

    // parallel

    const auto trg = mesh_mgr.get_triangle(0);
    renderer::core::breseham(
        buffer, 4 * trg.verts[0].y + 50, 4 * trg.verts[0].z + 50, 4 * trg.verts[1].y + 50, 4 * trg.verts[1].z + 50);
    renderer::core::breseham(
        buffer, 4 * trg.verts[1].y + 50, 4 * trg.verts[1].z + 50, 4 * trg.verts[2].y + 50, 4 * trg.verts[2].z + 50);
    renderer::core::breseham(
        buffer, 4 * trg.verts[2].y + 50, 4 * trg.verts[2].z + 50, 4 * trg.verts[0].y + 50, 4 * trg.verts[0].z + 50);

    save_pgm("test.ppm", buffer);

    spdlog::info("Exited sucessfully");

    return 0;
}
