#pragma once

#include <array>

template <typename T>
struct Point3
{
    T x;
    T y;
    T z;
};

using Point3f = Point3<float>;
using Point3i = Point3<int>;

struct Triangle
{
    std::array<Point3f, 3> verts;
};
