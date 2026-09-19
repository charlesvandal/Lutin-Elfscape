#include "PathLink.hpp"

PathLink::PathLink(const Point &position) : Object(ObjectType::PATH_LINK, "PathLink")
{
    setPositon(position);
}

bool PathLink::isFren(void)
{
    return false;
}

void PathLink::print(std::ostream &os) const
{
    os << ".";
}