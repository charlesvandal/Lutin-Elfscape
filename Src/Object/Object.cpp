#include "Object.hpp"

Object::Object(const ObjectType type, const std::string &name, const Point &position)
    : type{type}, name{name}, position{position}
{
}

void Object::setPositon(const Point &newPosition)
{
    position = newPosition;
}

const Point &Object::getPosition(void) const
{
    return position;
}

ObjectType Object::getType(void) const
{
    return type;
}

std::ostream &operator<<(std::ostream &os, const Object &_object)
{
    _object.print(os);
    return os;
}
