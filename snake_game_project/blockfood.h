#ifndef BLOCKFOOD_H
#define BLOCKFOOD_H

#include "block.h"

class BlockFood : public Block
{
public:
    BlockFood();

    int toxicity();
    void healthify();

    // Тот же Draw, что и в родительском классе, но цветной и с циферками
    virtual void draw(int x, int y, int size_in_px, QPainter *painter);

private:
    int _toxicity;
};

#endif // BLOCKFOOD_H
