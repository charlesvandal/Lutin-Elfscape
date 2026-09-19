#ifndef CAT_HPP
#define CAT_HPP

#include "Object.hpp"

#include <string>

class Cat : public Object
{
    public:
    Cat() = default;
    Cat(const std::string& name);
    ~Cat() = default;

    bool isFren(void) override;

    void print(std::ostream& os) const override;
};

#endif // CAT_HPP