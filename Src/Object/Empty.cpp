#include "Empty.hpp"

Empty::Empty(const Point &position) : Object(ObjectType::EMPTY, "empty")
{
    setPositon(position);
}

bool Empty::isFren(void)
{
    return true;
}

void Empty::print(std::ostream &os) const
{
    os << "_";
}