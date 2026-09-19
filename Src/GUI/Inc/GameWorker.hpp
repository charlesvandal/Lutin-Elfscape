#include <QObject>

#include "GameState.hpp"
#include "SimulatorBuilder.hpp"

class GameWorker : public QObject
{
    Q_OBJECT

public:
    explicit GameWorker(QObject *parent = nullptr);

public slots:
    void run();

signals:
    void stateChanged(const GameState &state);

private:
    std::unique_ptr<Simulator> simulator;
};