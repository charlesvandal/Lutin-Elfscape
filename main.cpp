#include <QApplication>
#include <QThread>
#include <QWidget>

#include "GUIConstants.hpp"
#include "GameBoardWidget.hpp"
#include "GameWorker.hpp"

int main(int argc, char* argv[])
{
    QThread* thread = new QThread;
    GameWorker* worker = new GameWorker;

    worker->moveToThread(thread);

    QObject::connect(thread, &QThread::started, worker, &GameWorker::run);

    thread->start();

    QApplication app(argc, argv);

    GameBoardWidget board(NUMBER_CELLS_X, NUMBER_CELLS_Y);

    board.resize(WINDOW_WIDTH_PX, WINDOW_HEIGHT_PX);
    board.setWindowTitle(APPLICATION_NAME);
    board.show();

    return app.exec();
}