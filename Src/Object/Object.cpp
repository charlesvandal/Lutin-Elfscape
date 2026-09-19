#include "Object.hpp"

Object::Object(const ObjectType type, const std::string& name)
    : type{type}, name{name}, position{0, 0}
{
}

void Object::setPositon(const Point& newPosition)
{
    position = newPosition;
}

const Point& Object::getPosition(void) const
{
    return position;
}

ObjectType Object::getType(void) const
{
    return type;
}

std::ostream& operator<<(std::ostream& os, const Object& _object)
{
    _object.print(os);
    return os;
}
