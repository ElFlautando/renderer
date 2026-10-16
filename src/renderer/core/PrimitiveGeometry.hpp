#pragma once

#include <array>
#include <format>
#include <spdlog/fmt/fmt.h>

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

template <typename T>
struct std::formatter<Point3<T>>
{
  public:
    constexpr auto parse(format_parse_context& ctx) { return ctx.begin(); }
    template <typename Context>
    constexpr auto format(Point3f const& point, Context& ctx) const
    {
        return format_to(ctx.out(), "(point3: {},{},{})", point.x, point.y, point.z);
    }
};

template <>
struct std::formatter<Triangle>
{
  public:
    constexpr auto parse(format_parse_context& ctx) { return ctx.begin(); }
    template <typename Context>
    constexpr auto format(Triangle const& tri, Context& ctx) const
    {
        return format_to(ctx.out(), "(Tris v0:{} v1:{} v2:{})", tri.verts[0], tri.verts[1], tri.verts[2]);
    }
};
