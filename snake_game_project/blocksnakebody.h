#ifndef BLOCKSNAKEBODY_H
#define BLOCKSNAKEBODY_H

#include "block.h"

class BlockSnakeBody : public Block
{
public:
    BlockSnakeBody();

    // Тот же Draw, что и в родительском классе, но зелёного цвета
    virtual void draw(int x, int y, int size_in_px, QPainter *painter);
};

#endif // BLOCKSNAKEBODY_H
