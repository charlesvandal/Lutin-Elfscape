#ifndef FLOWER_HPP
#define FLOWER_HPP

#include "Object.hpp"

#include <string>

class Flower : public Object
{
public:
    Flower() = default;
    Flower(const std::string &name, const Point &position);
    ~Flower() = default;

    bool isFren(void) override;

    void print(std::ostream &os) const override;
};

#endif // FLOWER_HPP