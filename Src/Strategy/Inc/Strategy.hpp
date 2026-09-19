#ifndef STRATEGY_HPP
#define STRATEGY_HPP

#include "Board.hpp"
#include "Object.hpp"
#include "Point.hpp"

class Strategy
{
    public:
    Strategy() = default;
    ~Strategy() = default;

    virtual Point execute(const Point& currentPosition, const Point& goalPosition,
                          const Surroundings_t& surroundings) = 0;
};

#endif // STRATEGY_HPP