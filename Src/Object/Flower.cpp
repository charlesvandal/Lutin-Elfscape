#include "Flower.hpp"

Flower::Flower(const std::string &name, const Point &position) : Object(ObjectType::FLOWER, name, position) {}

bool Flower::isFren(void)
{
    return true;
}

void Flower::print(std::ostream &os) const
{
    os << "F";
}