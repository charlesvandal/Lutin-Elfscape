#include "GameBoardWidget.hpp"
#include "GUIConstants.hpp"

#include <QPainter>
#include <algorithm>
#include <cstdlib>
#include <random>

GameBoardWidget::GameBoardWidget(int _rows, int _columns, QWidget *parent)
    : QWidget(parent),
      rows{_rows},
      columns{_columns},
      randomGridColors{getGridColors()},
      elfPixmap{QPixmap(AssetPaths::ELF)},
      flowerPixmap{QPixmap(AssetPaths::FLOWER)},
      firePixmap{QPixmap(AssetPaths::FIRE)},
      pathLinkPixmap{QPixmap(AssetPaths::PATH_LINK)}
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

    drawGrid(painter);
    drawObjects(painter);
}

void GameBoardWidget::drawGrid(QPainter &painter)
{
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

void GameBoardWidget::drawObjects(QPainter &painter)
{
    for (const ObjectDTO &object : gameState.objects)
    {
        drawObject(painter, object);
    }
}

void GameBoardWidget::drawObject(QPainter &painter, const ObjectDTO &object)
{
    switch (object.type)
    {
    case ObjectType::ELF:
    {
        drawPixmap(painter, object, elfPixmap);
        break;
    }
    case ObjectType::FLOWER:
    {
        drawPixmap(painter, object, flowerPixmap);
        break;
    }
    case ObjectType::FIRE:
    {
        drawPixmap(painter, object, firePixmap);
        break;
    }
    case ObjectType::PATH_LINK:
    {
        drawPixmap(painter, object, pathLinkPixmap);
        break;
    }
    default:
    {
        // Default to firePixmap for unknown object types
        break;
    }
    }
}

void GameBoardWidget::drawPixmap(QPainter &painter, const ObjectDTO &object, QPixmap &pixmap)
{
    const int cellWidth = width() / columns;
    const int cellHeight = height() / rows;

    const int x = object.position.x * cellWidth;
    const int y = object.position.y * cellHeight;

    const QRect cell(x, y, cellWidth, cellHeight);
    const QSize maxPixmapSize(cell.width() * PIXMAP_FILL_RATIO, cell.height() * PIXMAP_FILL_RATIO);
    const QSize pixmapSize{pixmap.size().scaled(maxPixmapSize, Qt::KeepAspectRatio)};
    const QRect pixmapRect{QPoint(cell.center().x() - pixmapSize.width() / 2,
                                  cell.center().y() - pixmapSize.height() / 2),
                           pixmapSize};

    painter.drawPixmap(pixmapRect, pixmap);
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
