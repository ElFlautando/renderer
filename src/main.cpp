
#include "Breseham.hpp"
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

    // parallel
    renderer::core::breseham(buffer, 50, 50, 50, 25);
    renderer::core::breseham(buffer, 50, 50, 50, 75);
    renderer::core::breseham(buffer, 50, 50, 25, 50);
    renderer::core::breseham(buffer, 50, 50, 75, 50);

    // diagonal
    renderer::core::breseham(buffer, 50, 50, 25, 25);
    renderer::core::breseham(buffer, 50, 50, 75, 75);
    renderer::core::breseham(buffer, 50, 50, 25, 75);
    renderer::core::breseham(buffer, 50, 50, 75, 25);

    // random
    renderer::core::breseham(buffer, 54, 25, 14, 5);
    renderer::core::breseham(buffer, 8, 6, 68, 99);

    save_pgm("test.ppm", buffer);

    return 0;
}
