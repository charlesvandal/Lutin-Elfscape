#ifndef GAME_BOARD_WIDGET_HPP
#define GAME_BOARD_WIDGET_HPP

#include <QWidget>
#include <vector>
#include <QPixmap>

#include "GameState.hpp"

class GameBoardWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GameBoardWidget(int _rows, int _columns, QWidget *parent = nullptr);

public slots:
    void setGameState(const GameState &state);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    std::vector<QColor> getGridColors(void);
    QColor getRandomGridColor(void);

    int rows;
    int columns;
    std::vector<QColor> randomGridColors;
    QPixmap protagonistPixmap;
    GameState gameState;
};

#endif // GAME_BOARD_WIDGET_HPP