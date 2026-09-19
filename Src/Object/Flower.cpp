#include "Flower.hpp"

Flower::Flower(const std::string& name) : Object(ObjectType::FLOWER, name) {}

bool Flower::isFren(void)
{
    return true;
}

void Flower::print(std::ostream& os) const
{
    os << "F";
}