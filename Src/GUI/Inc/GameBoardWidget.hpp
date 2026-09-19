#ifndef GAME_BOARD_WIDGET_HPP
#define GAME_BOARD_WIDGET_HPP

#include <QWidget>
#include <vector>

class GameBoardWidget : public QWidget
{
    Q_OBJECT

    public:
    explicit GameBoardWidget(int _rows, int _columns, QWidget* parent = nullptr);

    protected:
    void paintEvent(QPaintEvent* event) override;

    private:
    std::vector<QColor> getGridColors(void);
    QColor getRandomGridColor(void);

    int rows;
    int columns;
    std::vector<QColor> randomGridColors;
};

#endif // GAME_BOARD_WIDGET_HPP