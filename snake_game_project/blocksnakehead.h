#ifndef BLOCKSNAKEHEAD_H
#define BLOCKSNAKEHEAD_H

#include "block.h"


class BlockSnakeHead : public Block
{
public:
    BlockSnakeHead();

    QString direction();
    void set_direction(QString new_direction);

    // Тот же Draw, что и в родительском классе, но зелёного цвета и с глазиками
    virtual void draw(int x, int y, int size_in_px, QPainter *painter);

private:
    QString _direction = "";
};

#endif // BLOCKSNAKEHEAD_H
