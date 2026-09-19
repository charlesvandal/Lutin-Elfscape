#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "Defines.hpp"
#include "Point.hpp"

#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Object
{
    public:
    using Object_t = std::shared_ptr<Object>;

    Object() = default;
    Object(const ObjectType type, const std::string& name);
    ~Object() = default;

    virtual void setPositon(const Point& newPosition);
    virtual const Point& getPosition(void) const;

    virtual ObjectType getType(void) const;
    virtual bool isFren(void) = 0;

    virtual void print(std::ostream& os) const = 0;
    friend std::ostream& operator<<(std::ostream& os, const Object& _object);

    private:
    ObjectType type;
    std::string name;
    Point position;
};

#endif // OBJECT_HPP