#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include "Defines.hpp"
#include <QMetaType>
#include <vector>

struct ObjectDTO
{
    ObjectType type;
    Point position;
};

struct GameState
{
    std::vector<ObjectDTO> objects;
};

Q_DECLARE_METATYPE(GameState)

#endif // GAME_STATE_HPP