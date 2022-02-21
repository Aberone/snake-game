#include "blocksnakehead.h"
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QColor>

BlockSnakeHead::BlockSnakeHead()
{
    this->_type = "BlockSnakeHead";
}

QString BlockSnakeHead::direction()
{
    return this->_direction;
}

void BlockSnakeHead::set_direction(QString new_direction)
{
    this->_direction = new_direction;
}

void BlockSnakeHead::draw(int x, int y, int size_in_px, QPainter *painter)
{
    QColor cl_white(255, 255, 255, 255);
    QPen this_pen(cl_white);
    painter->setPen(this_pen);

    QColor cl_green(0, 225, 0, 255);
    QBrush this_brush(cl_green);
    painter->setBrush(this_brush);

    painter->drawRect(size_in_px * x, size_in_px * y, size_in_px, size_in_px);

    this_brush.setColor(cl_white);
    painter->setBrush(this_brush);
    int delta = size_in_px / 6;
    if (this->_direction == "up" || this->_direction == "left") {
        painter->drawEllipse(size_in_px * x + delta, size_in_px * y + delta,
                             size_in_px / 2 - 2 * delta, size_in_px / 2 - 2 * delta);
    }
    if (this->_direction == "left" || this->_direction == "down") {
        painter->drawEllipse(size_in_px * x + delta, size_in_px * y + size_in_px / 2 + delta,
                             size_in_px / 2 - 2 * delta, size_in_px / 2 - 2 * delta);
    }
    if (this->_direction == "down" || this->_direction == "right") {
        painter->drawEllipse(size_in_px * x + size_in_px / 2 + delta, size_in_px * y + size_in_px / 2 + delta,
                             size_in_px / 2 - 2 * delta, size_in_px / 2 - 2 * delta);
    }
    if (this->_direction == "right" || this->_direction == "up") {
        painter->drawEllipse(size_in_px * x + size_in_px / 2 + delta, size_in_px * y + delta,
                             size_in_px / 2 - 2 * delta, size_in_px / 2 - 2 * delta);
    }
}
