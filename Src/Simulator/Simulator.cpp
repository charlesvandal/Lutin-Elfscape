#include "Simulator.hpp"
#include "AppConstants.hpp"
#include "Empty.hpp"

#include <thread>

Simulator::Simulator(const Object::Object_t& protagonist, const Object::Object_t& goal,
                     std::unique_ptr<Strategy> strategy, const Board&& board)
    : protagonist(protagonist), goal(goal), strategy{std::move(strategy)}, board{std::move(board)},
      isDed{false}
{
}

void Simulator::run(void)
{
    while (doRunSimulation())
    {
        std::cout << board;

        const Point protagonistPosition{protagonist->getPosition()};
        const Surroundings_t surroundings{board.getSurroundings(protagonistPosition)};
        const Point currentPosition{protagonist->getPosition()};
        const Point newPosition =
            strategy->execute(currentPosition, goal->getPosition(), surroundings);

        if (willPepsi(newPosition, surroundings))
        {
            isDed = true;
        }

        protagonist->setPositon(newPosition);
        Object::Object_t empty = std::make_shared<Empty>(currentPosition);
        board.setCell(currentPosition.x, currentPosition.y, nullptr);
        board.setCell(newPosition.x, newPosition.y, protagonist);

        std::this_thread::sleep_for(SIMULATION_UPDATE_RATE_MS);
    }

    std::cout << board;
}

bool Simulator::doRunSimulation(void) const
{
    bool doRun{!goalAchieved()};
    doRun = !isDed && doRun;

    return doRun;
}

bool Simulator::goalAchieved(void) const
{
    const Point currentPosition{protagonist->getPosition()};
    const Point goalPosition{goal->getPosition()};
    const bool isGoalAchieved{currentPosition == goalPosition};

    return isGoalAchieved;
}

bool Simulator::willPepsi(const Point& newPosition, const Surroundings_t& surroundings) const
{
    bool pepsi{false};

    if (surroundings.north && (newPosition == surroundings.north->getPosition()) &&
        !surroundings.north->isFren())
    {
        pepsi = true;
    }
    else if (surroundings.south && (newPosition == surroundings.south->getPosition()) &&
             !surroundings.south->isFren())
    {
        pepsi = true;
    }
    else if (surroundings.east && (newPosition == surroundings.east->getPosition()) &&
             !surroundings.east->isFren())
    {
        pepsi = true;
    }
    else if (surroundings.west && (newPosition == surroundings.west->getPosition()) &&
             !surroundings.west->isFren())
    {
        pepsi = true;
    }

    return pepsi;
}
