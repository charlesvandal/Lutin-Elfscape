#ifndef FIRE_HPP
#define FIRE_HPP

#include "Object.hpp"

#include <string>

class Fire : public Object
{
public:
    Fire() = default;
    Fire(const std::string &name);
    ~Fire() = default;

    bool isFren(void) override;

    void print(std::ostream &os) const override;
};

#endif // FIRE_HPP