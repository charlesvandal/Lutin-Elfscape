#include "SimulatorBuilder.hpp"
#include "BoardBuilder.hpp"
#include "Elf.hpp"
#include "Flower.hpp"
#include "FlowerStrategy.hpp"

std::unique_ptr<Simulator> SimulatorBuilder::builSimulator(const uint8_t numberColumns,
                                                           const uint8_t numberRows)
{
    const Object::Object_t protagonist{std::make_shared<Elf>("Elfy")};
    const Object::Object_t target{std::make_shared<Flower>("Flower")};

    const Board board = BoardBuilder::buildBoard(protagonist, target);

    std::unique_ptr<Strategy> strategy{std::make_unique<FlowerStrategy>()};
    std::unique_ptr<Simulator> simulator{
        std::make_unique<Simulator>(protagonist, target, std::move(strategy), std::move(board))};

    return simulator;
}