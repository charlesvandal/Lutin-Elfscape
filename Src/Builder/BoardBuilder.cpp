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
                                          std::make_shared<Fire>("Fire5", InitialPositions::FIRE5)};
    return Board(numberColumns, numberRows, initialObjects);
}