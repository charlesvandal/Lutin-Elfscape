#include "Elf.hpp"

Elf::Elf(const std::string& name) : Object(ObjectType::ELF, name) {}

bool Elf::isFren(void)
{
    return true;
}

void Elf::print(std::ostream& os) const
{
    os << "A";
}