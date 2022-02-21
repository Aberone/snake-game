#include "gamefield.h"
#include "block.h"
#include "blockobstacle.h"
#include "blocksnakebody.h"
#include "blocksnakehead.h"
#include "blockfood.h"
#include "snake.h"
#include <QPainter>
#include <ctime>

GameField::GameField()
    :GameField(25, 25, 20, 20) {}

GameField::GameField(int blocks_along_x, int blocks_along_y, int block_size_in_px, int obstacles_account)
{
    this->_blocks_along_x = blocks_along_x + (5 - blocks_along_x) * (blocks_along_x < 5);
    this->_blocks_along_y = blocks_along_y + (5 - blocks_along_y) * (blocks_along_y < 5);
    this->_block_size_in_px = block_size_in_px + (5 - block_size_in_px) * (block_size_in_px < 5);
    obstacles_account = obstacles_account * (0 <= obstacles_account && obstacles_account + 4 < blocks_along_x * blocks_along_y);

    this->_field = QVector <QVector <Block*> > (this->_blocks_along_y,
                       QVector <Block*> (this->_blocks_along_x)
                   );
    for (int i = 0; i < this->_blocks_along_y; ++i) {
        for (int j = 0; j < this->_blocks_along_x; ++j) {
            this->_field[i][j] = new Block;
        }
    }

    this->_snake = new Snake(this);

    this->initialize_game(obstacles_account);
}

int GameField::blocks_along_x()
{
    return this->_blocks_along_x;
}

int GameField::blocks_along_y()
{
    return this->_blocks_along_y;
}

void GameField::end_game()
{
    this->_game_over = true;
}

bool GameField::game_over()
{
    return this->_game_over;
}

Snake* GameField::snake()
{
    return this->_snake;
}

void GameField::draw(QPainter *painter)
{
    for (int i = 0; i < this->_blocks_along_y; ++i) {
        for (int j = 0; j < this->_blocks_along_x; ++j) {
            this->_field[i][j]->draw(j, i, this->_block_size_in_px, painter);
        }
    }
}

void GameField::place(int x, int y, Block* block)
{
    delete this->_field[y][x];
    this->_field[y][x] = block;
}

void GameField::remove(int x, int y)
{
    delete this->_field[y][x];
    this->_field[y][x] = new Block;
}

void GameField::shift(int x0, int y0, int x1, int y1)
{
    delete this->_field[y1][x1];
    this->_field[y1][x1] = this->_field[y0][x0];
    this->_field[y0][x0] = new Block;
}

Block *GameField::at(int x, int y)
{
    return this->_field[y][x];
}

void GameField::spawn_food()
{
    std::srand(std::time(nullptr));

    bool spawned = false;
    int food_xpos, food_ypos;
    BlockFood* new_food = new BlockFood;
    while (!spawned) {
        food_xpos = 1 + std::rand() % (this->_blocks_along_x - 2);
        food_ypos = 1 + std::rand() % (this->_blocks_along_y - 2);
        if (this->_field[food_ypos][food_xpos]->type() == "Block") {
            this->place(food_xpos, food_ypos, new_food);
            spawned = true;
        }
    }
    this->_snake->connect_winding_manager(food_xpos, food_ypos, new_food);
}

void GameField::initialize_game(int obstacles_account)
{

    std::srand(std::time(nullptr));
    QVector <QVector <bool> > occupied(this->_blocks_along_y, QVector <bool>(this->_blocks_along_x, false));

    // Спавн змейки. Отмечаем несколько блоков перед её головой как занятые, чтоб не заспавнить там препятствия
    int snake_direction = std::rand() % 4;
    // up
    if (snake_direction == 0) {
        int snake_xpos = std::rand() % this->_blocks_along_x, snake_ypos = 2 + std::rand() % (this->_blocks_along_y - 4);
        this->_snake->place(snake_xpos, snake_ypos, "up");
        for (int i = -2; i <= 2; ++i) {
            occupied[snake_ypos + i][snake_xpos] = true;
        }
    }
    // left
    else if (snake_direction == 1) {
        int snake_xpos = 2 + std::rand() % (this->_blocks_along_x - 4), snake_ypos = std::rand() % this->_blocks_along_y;
        this->_snake->place(snake_xpos, snake_ypos, "left");
        for (int i = -2; i <= 2; ++i) {
            occupied[snake_ypos][snake_xpos + i] = true;
        }
    }
    // down
    else if (snake_direction == 2) {
        int snake_xpos = std::rand() % this->_blocks_along_x, snake_ypos = 2 + std::rand() % (this->_blocks_along_y - 4);
        this->_snake->place(snake_xpos, snake_ypos, "down");
        for (int i = -2; i <= 2; ++i) {
            occupied[snake_ypos + i][snake_xpos] = true;
        }
    }
    // right
    else if (snake_direction == 3) {
        int snake_xpos = 2 + std::rand() % (this->_blocks_along_x - 4), snake_ypos = std::rand() % this->_blocks_along_y;
        this->_snake->place(snake_xpos, snake_ypos, "right");
        for (int i = -2; i <= 2; ++i) {
            occupied[snake_ypos][snake_xpos + i] = true;
        }
    }

    // Спавн препятствий
    int cur_obstacles_account = 0;
    while (cur_obstacles_account < obstacles_account) {
        int obstacle_xpos = std::rand() % this->_blocks_along_x, obstacle_ypos = std::rand() % this->_blocks_along_y;
        if (!occupied[obstacle_ypos][obstacle_xpos]) {
            this->place(obstacle_xpos, obstacle_ypos, new BlockObstacle);
            occupied[obstacle_ypos][obstacle_xpos] = true;
            ++cur_obstacles_account;
        }
    }

    // Спавн еды
    this->spawn_food();
}

GameField::~GameField()
{
    for (int i = 0; i < this->_blocks_along_y; ++i) {
        for (int j = 0; j < this->_blocks_along_x; ++j) {
            delete this->_field[i][j];
        }
    }
}
