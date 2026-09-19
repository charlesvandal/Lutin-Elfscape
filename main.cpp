#include <QApplication>
#include <QMetaType>
#include <QThread>
#include <QWidget>

#include "GUIConstants.hpp"
#include "GameBoardWidget.hpp"
#include "GameWorker.hpp"

int main(int argc, char *argv[])
{
    QThread *thread = new QThread;
    GameWorker *worker = new GameWorker;

    QApplication app(argc, argv);
    qRegisterMetaType<GameState>();

    GameBoardWidget board(NUMBER_CELLS_X, NUMBER_CELLS_Y);

    worker->moveToThread(thread);

    QObject::connect(thread, &QThread::started, worker, &GameWorker::run);
    QObject::connect(worker, &GameWorker::stateChanged,
                     &board, &GameBoardWidget::setGameState,
                     Qt::QueuedConnection);

    thread->start();

    board.resize(WINDOW_WIDTH_PX, WINDOW_HEIGHT_PX);
    board.setWindowTitle(APPLICATION_NAME);
    board.show();

    return app.exec();
}