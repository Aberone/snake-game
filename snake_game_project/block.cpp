#include "block.h"
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QColor>

Block::Block()
{
    this->_type = "Block";
}

QString Block::type()
{
    return this->_type;
}

void Block::draw(int x, int y, int size_in_px, QPainter *painter)
{
    QColor cl_white(255, 255, 255, 255);
    QPen this_pen(cl_white);
    painter->setPen(this_pen);

    QColor cl_gray(200, 200, 200, 255);
    QBrush this_brush(cl_gray);
    painter->setBrush(this_brush);

    painter->drawRect(size_in_px * x, size_in_px * y, size_in_px, size_in_px);
}

Block::~Block() {}
