#include "Fire.hpp"

Fire::Fire(const std::string &name) : Object(ObjectType::FIRE, name) {}

bool Fire::isFren(void)
{
    return false;
}

void Fire::print(std::ostream &os) const
{
    os << "X";
}