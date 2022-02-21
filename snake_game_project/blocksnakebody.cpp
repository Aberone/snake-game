#include "blocksnakebody.h"
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QColor>

BlockSnakeBody::BlockSnakeBody()
{
    this->_type = "BlockSnakeBody";
}

void BlockSnakeBody::draw(int x, int y, int size_in_px, QPainter *painter)
{
    QColor cl_white(255, 255, 255, 255);
    QPen this_pen(cl_white);
    painter->setPen(this_pen);

    QColor cl_green(0, 225, 0, 255);
    QBrush this_brush(cl_green);
    painter->setBrush(this_brush);

    painter->drawRect(size_in_px * x, size_in_px * y, size_in_px, size_in_px);
}
