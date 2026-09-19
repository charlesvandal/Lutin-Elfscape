#ifndef ELF_HPP
#define ELF_HPP

#include "Object.hpp"

#include <string>

class Elf : public Object
{
    public:
    Elf() = default;
    Elf(const std::string& name);
    ~Elf() = default;

    bool isFren(void) override;

    void print(std::ostream& os) const override;
};

#endif // ELF_HPP