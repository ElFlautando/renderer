#pragma once

#include <vector>

namespace renderer::core
{
    void breseham(std::vector<std::vector<int>>& buffer, int x1, int y1, int x2, int y2);
} // namespace renderer::core
