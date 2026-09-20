#include "Elf.hpp"

Elf::Elf(const std::string &name, const Point &position) : Object(ObjectType::ELF, name, position) {}

bool Elf::isFren(void)
{
    return true;
}

void Elf::print(std::ostream &os) const
{
    os << "A";
}