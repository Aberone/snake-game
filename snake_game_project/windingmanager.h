#ifndef WINDINGMANAGER_H
#define WINDINGMANAGER_H

class BlockFood;

class WindingManager
{
public:
    WindingManager();

    // Соединяет змею со (свежезаспавненной) едой, начиная высчитывать число оборотов
    void set(int snake_x, int snake_y, int food_x, int food_y, BlockFood* food);
    // Обновляет угол поворота змеи (вызывается родительской змеёй после каждого движения)
    // Если он оказывается меньше -2pi, при этом вызывает healthify() для прикрепдённой еды
    void update(int new_snake_x, int new_snake_y);

private:
    int _food_x, _food_y, _snake_x, _snake_y;
    double _angle;
    BlockFood* _food;
};

#endif // WINDINGMANAGER_H
