#include "blockfood.h"
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QColor>
#include <ctime>


BlockFood::BlockFood()
{
    this->_type = "BlockFood";

    std::srand(std::time(nullptr));
    this->_toxicity = 3*(std::rand() % 2);
}

int BlockFood::toxicity()
{
    return this->_toxicity;
}

void BlockFood::healthify()
{
    if (this->_toxicity > 0) {
        this->_toxicity -= 1;
    }
}

void BlockFood::draw(int x, int y, int size_in_px, QPainter *painter)
{
    QColor cl_white(255, 255, 255, 255);
    QPen this_pen(cl_white);
    painter->setPen(this_pen);

    if (this->_toxicity == 0) {
        QColor cl_edible(255, 165, 0, 255);
        QBrush this_brush(cl_edible);
        painter->setBrush(this_brush);

        painter->drawRect(size_in_px * x, size_in_px * y, size_in_px, size_in_px);
    }
    else {
        QColor cl_poisonous(255, 0, 0, 255);
        QBrush this_brush(cl_poisonous);
        painter->setBrush(this_brush);

        painter->drawRect(size_in_px * x, size_in_px * y, size_in_px, size_in_px);

        if (this->_toxicity == 3) {
            painter->drawText(size_in_px * x, size_in_px * y, size_in_px, size_in_px, 0, "100");
        }
        else if (this->_toxicity == 2) {
            painter->drawText(size_in_px * x, size_in_px * y, size_in_px, size_in_px, 0, " 66");
        }
        else if (this->_toxicity == 1) {
            painter->drawText(size_in_px * x, size_in_px * y, size_in_px, size_in_px, 0, " 33");
        }
    }
}
