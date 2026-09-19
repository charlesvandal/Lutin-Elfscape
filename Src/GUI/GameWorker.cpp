#include "GameWorker.hpp"
#include "GUIConstants.hpp"

GameWorker::GameWorker(QObject *parent) : QObject(parent)
{
    simulator = SimulatorBuilder::builSimulator(NUMBER_CELLS_X, NUMBER_CELLS_Y);
}

void GameWorker::run()
{
    if (simulator)
    {
        while (true)
        {
            emit stateChanged(simulator->getState());
            simulator->execute();
        }
    }
}