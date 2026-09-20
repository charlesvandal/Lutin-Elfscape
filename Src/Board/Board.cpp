#include "Board.hpp"
#include "Empty.hpp"

#include <iostream>
#include <utility>

Board::Board(Grid_t &&_grid) : grid(std::move(_grid))
{
    initializePositions();
}

Board::Board(const std::uint8_t numberColumns, const std::uint8_t numberRows, const InitialObjects_t &initialObjects)
{
    buildGrid(numberColumns, numberRows, initialObjects);
}

Surroundings_t Board::getSurroundings(const Point &targetPosition) const
{
    Object::Object_t northObject{std::make_shared<Empty>()};
    Object::Object_t southObject{std::make_shared<Empty>()};
    Object::Object_t eastObject{std::make_shared<Empty>()};
    Object::Object_t westObject{std::make_shared<Empty>()};

    if (!grid.empty() && (targetPosition.y < grid.size()))
    {
        const Row_t targetRow = grid[targetPosition.y];

        if (targetPosition.y > 0U)
        {
            const Row_t northRow{grid[targetPosition.y - 1U]};

            if (!northRow.empty() && (targetPosition.x < northRow.size()))
            {
                northObject = northRow[targetPosition.x];
            }
        }
        if (targetPosition.y + 1U < grid.size())
        {
            const Row_t southRow = grid[targetPosition.y + 1U];

            if (!southRow.empty() && (targetPosition.x < southRow.size()))
            {
                southObject = southRow[targetPosition.x];
            }
        }
        if (targetPosition.x + 1U < targetRow.size())
        {
            eastObject = targetRow[targetPosition.x + 1U];
        }
        if (targetPosition.x > 0U)
        {
            westObject = targetRow[targetPosition.x - 1U];
        }
    }

    return {northObject, southObject, eastObject, westObject};
}

Object::Object_t Board::getCell(const std::uint8_t columnIndex, const std::uint8_t rowIndex) const
{
    Object::Object_t object{nullptr};

    if (!grid.empty())
    {
        if (rowIndex < grid.at(0).size())
        {
            Row_t row{grid.at(rowIndex)};

            if (columnIndex < row.size())
            {
                object = row.at(columnIndex);
            }
        }
    }

    return object;
}

void Board::setCell(const std::uint8_t columnIndex, const std::uint8_t rowIndex,
                    const Object::Object_t object)
{
    if (!grid.empty())
    {
        if (rowIndex < grid.at(0).size())
        {
            Row_t &row{grid.at(rowIndex)};

            if (columnIndex < row.size())
            {
                row[columnIndex] = object;
            }
        }
    }
}

const Grid_t &Board::getGrid(void) const
{
    return grid;
}

void Board::buildGrid(const std::uint8_t numberColumns, const std::uint8_t numberRows, const InitialObjects_t &initialObjects)
{
    resizeGrid(numberColumns, numberRows);
    initializePositions();
    addInitialObjects(initialObjects);
}

void Board::resizeGrid(const std::uint8_t numberColumns, const std::uint8_t numberRows)
{
    grid.resize(numberRows);

    for (auto &row : grid)
    {
        row.resize(numberColumns);
    }
}

void Board::initializePositions(void)
{
    for (size_t rowIndex = 0; rowIndex < grid.size(); rowIndex++)
    {
        Row_t row{grid.at(rowIndex)};

        for (size_t columnIndex = 0; columnIndex < row.size(); columnIndex++)
        {
            Object::Object_t object{row.at(columnIndex)};

            if (object)
            {
                Point position{columnIndex, rowIndex};
                object->setPositon(position);
            }
            else
            {
                const Point position{columnIndex, rowIndex};
                Object::Object_t emptyObject = std::make_shared<Empty>(position);
                grid[rowIndex][columnIndex] = emptyObject;
            }
        }
    }
}

void Board::addInitialObjects(const InitialObjects_t &initialObjects)
{
    for (auto object : initialObjects)
    {
        if (object)
        {
            const Point position{object->getPosition()};

            if (position.x < grid.at(0).size() && position.y < grid.size())
            {
                grid[position.y][position.x] = object;
            }
        }
    }
}

std::ostream &operator<<(std::ostream &os, const Board &board)
{
    if (!board.getGrid().empty())
    {
        os << " ";

        for (size_t i = 0; i < board.getGrid().size(); i++)
        {
            os << "_ ";
        }

        os << std::endl;
    }

    for (auto row : board.getGrid())
    {
        os << "|";

        for (auto object : row)
        {
            if (object)
            {
                os << *object << "|";
            }
            else
            {
                os << "_|";
            }
        }

        os << std::endl;
    }

    return os;
}
