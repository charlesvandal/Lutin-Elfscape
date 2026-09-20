#ifndef BOARD_BUILDER_HPP
#define BOARD_BUILDER_HPP

#include "Board.hpp"

class BoardBuilder
{
public:
    static Board buildBoard(const Object::Object_t &protagonist, const Object::Object_t &target,
                            const uint8_t numberColumns, const uint8_t numberRows);

private:
    BoardBuilder() = delete;
    BoardBuilder(BoardBuilder &) = delete;
    BoardBuilder(BoardBuilder &&) = delete;
    BoardBuilder(const BoardBuilder &) = delete;
    BoardBuilder(const BoardBuilder &&) = delete;
    ~BoardBuilder() = delete;
};

#endif // BOARD_BUILDER_HPP