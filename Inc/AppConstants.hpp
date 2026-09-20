#ifndef APP_CONSTANTS
#define APP_CONSTANTS

#include <chrono>
#include "Point.hpp"

const std::chrono::milliseconds SIMULATION_UPDATE_RATE_MS{500};
constexpr Point ZERO_POSITION{0UL, 0UL};

namespace InitialPositions
{
    constexpr Point PROTAGONIST{19UL, 19UL};
    constexpr Point TARGET{1UL, 2UL};
    constexpr Point FIRE1{4UL, 2UL};
    constexpr Point FIRE2{5UL, 2UL};
    constexpr Point FIRE3{10UL, 2UL};
    constexpr Point FIRE4{15UL, 6UL};
    constexpr Point FIRE5{16UL, 7UL};
    constexpr Point FIRE6{18UL, 14UL};
    constexpr Point FIRE7{17UL, 14UL};
    constexpr Point FIRE8{19UL, 15UL};
    constexpr Point FIRE9{1UL, 14UL};
    constexpr Point FIRE10{4UL, 16UL};
}

#endif // APP_CONSTANTS