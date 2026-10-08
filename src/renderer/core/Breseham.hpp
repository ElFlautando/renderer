#pragma once

#include <vector>

namespace renderer::core
{
    void breseham(std::vector<std::vector<int>>& buffer, int x0, int y0, int x1, int y1);
} // namespace renderer::core
