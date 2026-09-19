#include "FlowerStrategy.hpp"

FlowerStrategy::FlowerStrategy()
    : Strategy(), currentPosition{}, currentSurroundings{}, doEsquiveManeuver{false}
{
}

Point FlowerStrategy::execute(const Point& _currentPosition, const Point& goalPosition,
                              const Surroundings_t& surroundings)
{
    Point newPosition{_currentPosition};
    currentPosition = _currentPosition;
    currentSurroundings = surroundings;

    if (goalPosition.y < currentPosition.y)
    {
        if (surroundings.north && surroundings.north->isFren())
        {
            --newPosition.y;
        }
        else
        {
            esquiveNorthFoe(newPosition);
        }
    }
    else if (goalPosition.y > currentPosition.y)
    {
        if (surroundings.south && surroundings.south->isFren())
        {
            ++newPosition.y;
        }
        else
        {
            esquiveSouthFoe(newPosition);
        }
    }
    else if (goalPosition.x < currentPosition.x)
    {
        if (surroundings.west && surroundings.west->isFren())
        {
            --newPosition.x;
        }
        else
        {
            esquiveWestFoe(newPosition);
        }
    }
    else if (goalPosition.x > currentPosition.x)
    {
        if (surroundings.east && surroundings.east->isFren())
        {
            ++newPosition.x;
        }
        else
        {
            esquiveEastFoe(newPosition);
        }
    }

    return newPosition;
}

void FlowerStrategy::esquiveNorthFoe(Point& newPosition)
{
    if ((currentPosition.x > 0) && currentSurroundings.west && currentSurroundings.west->isFren())
    {
        --newPosition.x;
        doEsquiveManeuver = true;
    }
    else if (currentSurroundings.east && currentSurroundings.east->isFren())
    {
        ++newPosition.x;
        doEsquiveManeuver = true;
    }
    else if (currentSurroundings.south && currentSurroundings.south->isFren())
    {
        ++newPosition.y;
        doEsquiveManeuver = true;
    }
    else
    {
        --newPosition.y;
        doEsquiveManeuver = false;
    }
}

void FlowerStrategy::esquiveSouthFoe(Point& newPosition)
{
    if ((currentPosition.x > 0) && currentSurroundings.west && currentSurroundings.west->isFren())
    {
        --newPosition.x;
        doEsquiveManeuver = true;
    }
    else if (currentSurroundings.east && currentSurroundings.east->isFren())
    {
        ++newPosition.x;
        doEsquiveManeuver = true;
    }
    else if (currentSurroundings.north && currentSurroundings.north->isFren())
    {
        --newPosition.y;
        doEsquiveManeuver = true;
    }
    else
    {
        ++newPosition.y;
        doEsquiveManeuver = false;
    }
}

void FlowerStrategy::esquiveWestFoe(Point& newPosition)
{
    if ((currentPosition.y > 0) && currentSurroundings.north && currentSurroundings.north->isFren())
    {
        --newPosition.y;
        doEsquiveManeuver = true;
    }
    else if (currentSurroundings.south && currentSurroundings.south->isFren())
    {
        ++newPosition.y;
        doEsquiveManeuver = true;
    }
    else if (currentSurroundings.east && currentSurroundings.east->isFren())
    {
        ++newPosition.x;
        doEsquiveManeuver = true;
    }
    else
    {
        --newPosition.x;
        doEsquiveManeuver = false;
    }
}

void FlowerStrategy::esquiveEastFoe(Point& newPosition)
{
    if ((currentPosition.y > 0) && currentSurroundings.north && currentSurroundings.north->isFren())
    {
        --newPosition.y;
        doEsquiveManeuver = true;
    }
    else if (currentSurroundings.south && currentSurroundings.south->isFren())
    {
        ++newPosition.y;
        doEsquiveManeuver = true;
    }
    else if (currentSurroundings.west && currentSurroundings.west->isFren())
    {
        --newPosition.x;
        doEsquiveManeuver = true;
    }
    else
    {
        ++newPosition.x;
        doEsquiveManeuver = false;
    }
}
