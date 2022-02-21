#ifndef BLOCKOBSTACLE_H
#define BLOCKOBSTACLE_H

#include "block.h"

class BlockObstacle : public Block
{
public:
    BlockObstacle();

    // Тот же Draw, что и в родительском классе, но чёрного цвета
    virtual void draw(int x, int y, int size_in_px, QPainter *painter);
};

#endif // BLOCKOBSTACLE_H
