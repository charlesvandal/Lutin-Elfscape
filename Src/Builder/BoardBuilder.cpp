#include "BoardBuilder.hpp"
#include "AppConstants.hpp"
#include "Fire.hpp"

Board BoardBuilder::buildBoard(const Object::Object_t &protagonist, const Object::Object_t &target,
                               const uint8_t numberColumns, const uint8_t numberRows)
{
    const InitialObjects_t initialObjects{protagonist, target,
                                          std::make_shared<Fire>("Fire1", InitialPositions::FIRE1),
                                          std::make_shared<Fire>("Fire2", InitialPositions::FIRE2),
                                          std::make_shared<Fire>("Fire3", InitialPositions::FIRE3),
                                          std::make_shared<Fire>("Fire4", InitialPositions::FIRE4),
                                          std::make_shared<Fire>("Fire5", InitialPositions::FIRE5),
                                          std::make_shared<Fire>("Fire6", InitialPositions::FIRE6),
                                          std::make_shared<Fire>("Fire7", InitialPositions::FIRE7),
                                          std::make_shared<Fire>("Fire8", InitialPositions::FIRE8),
                                          std::make_shared<Fire>("Fire9", InitialPositions::FIRE9),
                                          std::make_shared<Fire>("Fire10", InitialPositions::FIRE10)};
    return Board(numberColumns, numberRows, initialObjects);
}