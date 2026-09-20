#ifndef SIMULATOR_HPP
#define SIMULATOR_HPP

#include "Board.hpp"
#include "GameState.hpp"
#include "Strategy.hpp"

#include <memory>

class Simulator
{
public:
    Simulator(const Object::Object_t &protagonist, const Object::Object_t &goal,
              std::unique_ptr<Strategy> strategy, const Board &&board);
    ~Simulator() = default;

    void execute(void);
    GameState getState(void) const;

private:
    Simulator() = delete;

    Point getProtagonistNewPosition(void);
    void moveProtagonist(const Point &newPosition);
    bool goalAchieved(void) const;
    bool willPepsi(const Point &newPosition, const Surroundings_t &surroundings) const;

    Object::Object_t protagonist;
    Object::Object_t goal;
    std::unique_ptr<Strategy> strategy;
    Board board;
    bool isDed;
};

#endif // SIMULATOR_HPP