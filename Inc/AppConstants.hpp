#ifndef APP_CONSTANTS
#define APP_CONSTANTS

#include <chrono>
#include "Point.hpp"

const std::chrono::milliseconds SIMULATION_UPDATE_RATE_MS{1000};
constexpr Point ZERO_POSITION{0UL, 0UL};

namespace InitialPositions
{
    constexpr Point PROTAGONIST{7UL, 7UL};
    constexpr Point TARGET{10UL, 3UL};
    constexpr Point FIRE1{1UL, 4UL};
    constexpr Point FIRE2{1UL, 5UL};
    constexpr Point FIRE3{2UL, 3UL};
    constexpr Point FIRE4{3UL, 3UL};
    constexpr Point FIRE5{4UL, 2UL};
}

#endif // APP_CONSTANTS