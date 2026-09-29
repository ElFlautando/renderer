
#include <fstream>
#include <print>
#include <ranges>
#include <spdlog/spdlog.h>
#include <vector>

void breseham(std::vector<std::vector<int>>& buffer, int x1, int y1, int x2, int y2)
{
    auto dx = x2 - x1;
    auto dy = y2 - y1;

    auto y = y1;

    buffer[x1][y] = 255;

    auto err = dx / 2.0F;

    for (const auto x : std::ranges::views::iota(x1 + 1, x2))
    {
        err -= dy;
        if (err < 0)
        {
            y += 1;
            err += dx;
        }
        buffer[x][y] = 255;
    }
}

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

    breseham(buffer, 0, 0, 10, 5);
    breseham(buffer, 0, 0, 20 , 0);
    breseham(buffer, 0, 0, 30 , 30);
    save_pgm("test.ppm", buffer);

    return 0;
}
