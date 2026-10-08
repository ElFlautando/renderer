#include "Breseham.hpp"
#include <cmath>
#include <cstdlib>
#include <ranges>

void renderer::core::breseham(std::vector<std::vector<int>>& buffer, int x0, int y0, int x1, int y1)
{
    auto dx = x1 - x0;
    auto dy = y1 - y0;

    const auto incx = std::copysign(1, dx);
    const auto incy = std::copysign(1, dy);

    dx = std::abs(x1 - x0);
    dy = std::abs(y1 - y0);

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

    auto x = x0;
    auto y = y0;
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
