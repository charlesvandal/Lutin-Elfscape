#ifndef APP_CONSTANTS
#define APP_CONSTANTS

#include <chrono>
#include "Point.hpp"

const std::chrono::milliseconds SIMULATION_UPDATE_RATE_MS{1000};
constexpr Point ZERO_POSITION{0UL, 0UL};

namespace InitialPositions
{
    constexpr Point PROTAGONIST{7UL, 7UL};
    constexpr Point TARGET{1UL, 3UL};
}

#endif // APP_CONSTANTS