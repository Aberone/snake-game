#include "blockobstacle.h"
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QColor>

BlockObstacle::BlockObstacle()
{
    this->_type = "BlockObstacle";
}

void BlockObstacle::draw(int x, int y, int size_in_px, QPainter *painter)
{
    QColor cl_white(255, 255, 255, 255);
    QPen this_pen(cl_white);
    painter->setPen(this_pen);

    QColor cl_black(0, 0, 0, 255);
    QBrush this_brush(cl_black);
    painter->setBrush(this_brush);

    painter->drawRect(size_in_px * x, size_in_px * y, size_in_px, size_in_px);
}
