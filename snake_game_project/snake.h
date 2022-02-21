#ifndef SNAKE_H
#define SNAKE_H

#include <QVector>
class GameField;
class BlockSnakeHead;
class BlockFood;
class WindingManager;

class Snake
{
public:
    Snake(GameField* host);

    // Помещает змейку на игровое поле, с головой на позиции (x, y) и взглядом в направлении direction
    void place(int x, int y, QString direction);
    // Предпринимает попытку развернуть голову в укзаанном направлении
    void try_to_change_direction(QString new_direction);
    // Двигается на одну клетку, обрабатывая события столкновения или поглощения еды
    void move();
    // Соединяет Winding Manager с блоком еды на позиции (x, y), заставляя его начать отсчитывать обороты
    void connect_winding_manager(int food_x, int food_y, BlockFood* food);

private:
    GameField* _host;
    BlockSnakeHead* _head;
    WindingManager* _wm;
    int _dx, _dy;
    QVector <int> _snake_x, _snake_y;
};

#endif // SNAKE_H
