#ifndef FLOWER_STRATEGY_HPP
#define FLOWER_STRATEGY_HPP

#include "Board.hpp"
#include "Strategy.hpp"

class FlowerStrategy : public Strategy
{
    public:
    FlowerStrategy();
    ~FlowerStrategy() = default;

    Point execute(const Point& currentPosition, const Point& goalPosition,
                  const Surroundings_t& surroundings) override;

    private:
    void esquiveNorthFoe(Point& newPosition);
    void esquiveSouthFoe(Point& newPosition);
    void esquiveWestFoe(Point& newPosition);
    void esquiveEastFoe(Point& newPosition);

    Point currentPosition;
    Surroundings_t currentSurroundings;
    bool doEsquiveManeuver;
};

#endif // FLOWER_STRATEGY_HPP