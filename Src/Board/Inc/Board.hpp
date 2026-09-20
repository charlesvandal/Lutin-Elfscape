#ifndef BOARD_HPP
#define BOARD_HPP

#include "Defines.hpp"
#include "Object.hpp"

#include <cstdint>
#include <memory>
#include <vector>

using Row_t = std::vector<Object::Object_t>;
using Grid_t = std::vector<Row_t>;
using InitialObjects_t = std::vector<Object::Object_t>;

struct Surroundings_t
{
    Object::Object_t north;
    Object::Object_t south;
    Object::Object_t east;
    Object::Object_t west;
};

class Board
{
public:
    Board() = default;
    Board(Grid_t &&_grid);
    Board(const std::uint8_t numberColumns, const std::uint8_t numberRows, const InitialObjects_t &initialObjects);
    ~Board() = default;

    Surroundings_t getSurroundings(const Point &targetPosition) const;

    Object::Object_t getCell(const std::uint8_t columnIndex, const std::uint8_t rowIndex) const;
    void setCell(const std::uint8_t columnIndex, const std::uint8_t rowIndex,
                 const Object::Object_t object);

    const Grid_t &getGrid(void) const;

    friend std::ostream &operator<<(std::ostream &os, const Board &board);

private:
    void buildGrid(const std::uint8_t numberColumns, const std::uint8_t numberRows, const InitialObjects_t &initialObjects);
    void resizeGrid(const std::uint8_t numberColumns, const std::uint8_t numberRows);
    void initializePositions(void);
    void addInitialObjects(const InitialObjects_t &initialObjects);

    Grid_t grid;
};

#endif // BOARD_HPP