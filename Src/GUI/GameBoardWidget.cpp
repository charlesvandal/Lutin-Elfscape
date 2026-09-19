#include "GameBoardWidget.hpp"
#include "GUIConstants.hpp"

#include <QPainter>
#include <algorithm>
#include <cstdlib>
#include <random>

GameBoardWidget::GameBoardWidget(int _rows, int _columns, QWidget *parent)
    : QWidget(parent), rows{_rows}, columns{_columns}, randomGridColors{getGridColors()}, protagonistPixmap(AssetPaths::ELF)
{
    setMinimumSize(MINIMUM_WINDOW_WIDTH_PX, MINIMUM_WINDOW_HEIGHT_PX);
}

void GameBoardWidget::setGameState(const GameState &state)
{
    gameState = state;
    update();
}

void GameBoardWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing, false);

    const int cellWidth = width() / columns;
    const int cellHeight = height() / rows;

    size_t colorIndex{0U};

    for (int row = 0; row < rows; ++row)
    {
        for (int column = 0; column < columns; ++column)
        {
            const QColor cellColor{randomGridColors[colorIndex]};
            const QRect cell(column * cellWidth, row * cellHeight, cellWidth, cellHeight);

            painter.fillRect(cell, cellColor);
            painter.setPen(QPen(Qt::white, 3));
            painter.drawRect(cell);

            ++colorIndex;
        }
    }
}

std::vector<QColor> GameBoardWidget::getGridColors(void)
{
    std::vector<QColor> colors{};

    for (int row = 0; row < rows; ++row)
    {
        for (int column = 0; column < columns; ++column)
        {
            const QColor cellColor{getRandomGridColor()};
            colors.push_back(cellColor);
        }
    }

    return colors;
}

QColor GameBoardWidget::getRandomGridColor(void)
{
    const size_t numberColors{GridColors::COLORS.size()};
    const size_t randomIndex{rand() % numberColors};
    const QColor randomColor{GridColors::COLORS[randomIndex]};

    return randomColor;
}
