#ifndef BLOCK_H
#define BLOCK_H

#include <QString>
class QPainter;


class Block
{
public:
    Block();

    QString type();

    // Отрисовка квадартика размером size_in_px, отсчитывая от левого верхнего угла (x, y)
    virtual void draw(int x, int y, int size_in_px, QPainter *painter);

    virtual ~Block();

protected:
    QString _type;
};

#endif // BLOCK_H
