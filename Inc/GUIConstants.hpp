#ifndef GUI_CONSTANTS
#define GUI_CONSTANTS

#include <QColor>
#include <QString>
#include <cstdint>
#include <string>
#include <vector>

const QString APPLICATION_NAME{"Lutin Elfscape"};

constexpr std::uint64_t NUMBER_CELLS_X{8U};
constexpr std::uint64_t NUMBER_CELLS_Y{8U};

constexpr int MINIMUM_WINDOW_WIDTH_PX{400U};
constexpr int MINIMUM_WINDOW_HEIGHT_PX{400U};

constexpr int WINDOW_WIDTH_PX{800U};
constexpr int WINDOW_HEIGHT_PX{800U};

namespace GridColors
{
    constexpr QColor LIGHT_BLUE{52, 141, 199};
    constexpr QColor BLUE{74, 80, 166};
    constexpr QColor LIGHT_PINK{238, 166, 203};
    constexpr QColor PINK{224, 93, 143};
    constexpr QColor INDIGO{90, 59, 152};
    constexpr QColor GREEN{143, 190, 60};
    constexpr QColor TURQUOISE{36, 182, 119};
    constexpr QColor YELLOW{252, 222, 110};
    constexpr QColor ORANGE{233, 131, 82};
    constexpr QColor PURPLE{157, 67, 154};
    constexpr QColor RED{222, 66, 67};

    const std::vector<QColor> COLORS{GridColors::LIGHT_BLUE, GridColors::BLUE, GridColors::LIGHT_PINK,
                                     GridColors::PINK, GridColors::INDIGO, GridColors::GREEN,
                                     GridColors::TURQUOISE, GridColors::YELLOW, GridColors::ORANGE,
                                     GridColors::PURPLE, GridColors::RED};
} // namespace GridColors

namespace AssetPaths
{
    const QString ELF{":/images/Assets/elf.png"};
} // namespace AssetPaths

#endif // GUI_CONSTANTS