#include "Cat.hpp"

Cat::Cat(const std::string &name) : Object(ObjectType::CAT, name) {}

bool Cat::isFren(void)
{
    return true;
}

void Cat::print(std::ostream &os) const
{
    os << "W";
}