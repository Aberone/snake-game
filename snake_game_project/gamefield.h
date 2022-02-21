#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include <QVector>
class QPainter;
class Block;
class BlockObstacle;
class Snake;

class GameField
{
public:
    GameField();
    GameField(int blocks_along_x, int blocks_along_y, int block_size_in_px, int obstacles_account);

    int blocks_along_x();
    int blocks_along_y();
    void end_game();
    bool game_over();
    Snake* snake();

    // Отрисовывает игровое поле
    void draw(QPainter *painter);
    // Помещает переданный по указателю блок на позицию (x, y), удаляя с неё предыдущий
    void place(int x, int y, Block* block);
    // Удаляет с позиции (x, y) блок (т.е. заменяет его на пустой блок)
    void remove(int x, int y);
    // Перемещает блок с позиции (x0, y0) на позицию (x1, y1).
    // Блок, который был на (x1, y1), удаляется, на (x0, y0) помещается пустой блок.
    void shift(int x0, int y0, int x1, int y1);
    // Указатель на блок, находящийся на позиции (x, y)
    Block* at(int x, int y);
    // Спавнит еду в случайном месте, оповещает об этом змею
    void spawn_food();
    // Инициализирует игровое поле в соответствии с условием лабы
    void initialize_game(int obstacles_account);

    ~GameField();

private:
    int _blocks_along_x, _blocks_along_y, _block_size_in_px;
    bool _game_over = false;
    QVector <QVector <Block*> > _field;

    Snake* _snake;
};

#endif // GAMEFIELD_H
