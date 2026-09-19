#ifndef POINT_HPP
#define POINT_HPP

#include <cstdint>

struct Point
{
    std::uint64_t x;
    std::uint64_t y;

    bool operator==(const Point& point) const
    {
        const bool isEqual{(point.x == x) && (point.y == y)};

        return isEqual;
    }
};

#endif