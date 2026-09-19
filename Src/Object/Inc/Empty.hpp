#ifndef EMPTY_HPP
#define EMPTY_HPP

#include "Object.hpp"

#include <string>

class Empty : public Object
{
    public:
    Empty() = default;
    Empty(const Point& position);
    ~Empty() = default;

    bool isFren(void) override;

    void print(std::ostream& os) const override;
};

#endif // EMPTY_HPP