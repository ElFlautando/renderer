#include "Breseham.hpp"
#include <cmath>
#include <cstdlib>
#include <ranges>

void renderer::core::breseham(std::vector<std::vector<int>>& buffer, int x1, int y1, int x2, int y2)
{
    auto dx = x2 - x1;
    auto dy = y2 - y1;

    const auto incx = std::copysign(1, dx);
    const auto incy = std::copysign(1, dy);

    dx = std::abs(x2 - x1);
    dy = std::abs(y2 - y1);

    const auto ddx = incx;
    const auto ddy = incy;

    auto pdx = 0;
    auto pdy = 0;

    auto delta_slow = 0;
    auto delta_fast = 0;

    if (dx > dy)
    {
        pdx = incx;
        pdy = 0;
        delta_slow = dy;
        delta_fast = dx;
    }
    else
    {
        pdx = 0;
        pdy = incy;
        delta_slow = dx;
        delta_fast = dy;
    }

    auto x = x1;
    auto y = y1;
    auto err = delta_fast / 2;
    buffer[x][y] = 255;

    for (const auto _ : std::ranges::views::iota(0, delta_fast))
    {
        err -= delta_slow;
        if (err < 0)
        {
            err += delta_fast;
            x += ddx;
            y += ddy;
        }
        else
        {
            x += pdx;
            y += pdy;
        }

        buffer[x][y] = 255;
    }
}
