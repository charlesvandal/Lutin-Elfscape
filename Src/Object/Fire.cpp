#include "Fire.hpp"

Fire::Fire(const std::string &name, const Point &position) : Object(ObjectType::FIRE, name, position) {}

bool Fire::isFren(void)
{
    return false;
}

void Fire::print(std::ostream &os) const
{
    os << "X";
}