#ifndef PATH_LINK_HPP
#define PATH_LINK_HPP

#include "Object.hpp"

#include <string>

class PathLink : public Object
{
public:
    PathLink() = default;
    PathLink(const Point &position);
    ~PathLink() = default;

    bool isFren(void) override;

    void print(std::ostream &os) const override;
};

#endif // PATH_LINK_HPP