#include "BoardBuilder.hpp"
#include "Cat.hpp"
#include "Fire.hpp"

Board BoardBuilder::buildBoard(const Object::Object_t& protagonist, const Object::Object_t& target)
{
    Object::Object_t cat1 = std::make_shared<Cat>("Yoko");
    Object::Object_t cat2 = std::make_shared<Cat>("Leo");
    Object::Object_t fire1 = std::make_shared<Fire>("Fire1");
    Object::Object_t fire2 = std::make_shared<Fire>("Fire2");
    Object::Object_t fire3 = std::make_shared<Fire>("Fire3");
    Object::Object_t fire4 = std::make_shared<Fire>("Fire4");
    Object::Object_t fire5 = std::make_shared<Fire>("Fire5");
    Object::Object_t fire6 = std::make_shared<Fire>("Fire6");

    Grid_t grid{{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
                {nullptr, cat1, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
                {nullptr, nullptr, nullptr, nullptr, fire6, nullptr, nullptr, nullptr},
                {nullptr, target, fire2, fire4, nullptr, nullptr, nullptr, nullptr},
                {nullptr, fire1, nullptr, nullptr, nullptr, cat2, nullptr, nullptr},
                {nullptr, fire5, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
                {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
                {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, protagonist}};

    return Board(std::move(grid));
}

Board BoardBuilder::buildBoard(const uint8_t numberColumns, const uint8_t numberRows)
{
    return Board(numberColumns, numberRows);
}