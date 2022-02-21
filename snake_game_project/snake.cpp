#include "snake.h"
#include "blocksnakehead.h"
#include "blocksnakebody.h"
#include "blockfood.h"
#include "windingmanager.h"
#include "gamefield.h"

Snake::Snake(GameField *host)
{
    this->_host = host;
    this->_wm = new WindingManager;
}

void Snake::place(int x, int y, QString direction)
{
    if (direction == "up") {
        this->_dx = 0;
        this->_dy = -1;
    }
    else if (direction == "left") {
        this->_dx = -1;
        this->_dy = 0;
    }
    else if (direction == "down") {
        this->_dx = 0;
        this->_dy = 1;
    }
    else if (direction == "right") {
        this->_dx = 1;
        this->_dy = 0;
    }

    this->_snake_x.append(x);
    this->_snake_y.append(y);
    this->_snake_x.append(x - this->_dx);
    this->_snake_y.append(y - this->_dy);
    this->_snake_x.append(x - 2*this->_dx);
    this->_snake_y.append(y - 2*this->_dy);

    this->_head = new BlockSnakeHead;
    this->_head->set_direction(direction);
    this->_host->place(x, y, this->_head);
    this->_host->place(x - this->_dx, y - this->_dy, new BlockSnakeBody);
    this->_host->place(x - 2*this->_dx, y - 2*this->_dy, new BlockSnakeBody);
}

void Snake::try_to_change_direction(QString new_direction)
{
    if (new_direction == "up" && !(this->_snake_x[0] == this->_snake_x[1] && this->_snake_y[0] - 1 == this->_snake_y[1])) {
        this->_dx = 0;
        this->_dy = -1;
        this->_head->set_direction(new_direction);
    }
    else if (new_direction == "left" && !(this->_snake_x[0] - 1 == this->_snake_x[1] && this->_snake_y[0] == this->_snake_y[1])) {
        this->_dx = -1;
        this->_dy = 0;
        this->_head->set_direction(new_direction);
    }
    else if (new_direction == "down" && !(this->_snake_x[0] == this->_snake_x[1] && this->_snake_y[0] + 1 == this->_snake_y[1])) {
        this->_dx = 0;
        this->_dy = 1;
        this->_head->set_direction(new_direction);
    }
    else if (new_direction == "right" && !(this->_snake_x[0] + 1 == this->_snake_x[1] && this->_snake_y[0] == this->_snake_y[1])) {
        this->_dx = 1;
        this->_dy = 0;
        this->_head->set_direction(new_direction);
    }
}

void Snake::move()
{
    // Натыкается на препятствие, край карты или на свой хвост
    int xto = this->_snake_x[0] + this->_dx, yto = this->_snake_y[0] + this->_dy;
    if (xto < 0 || xto >= this->_host->blocks_along_x() || yto < 0 || yto >= this->_host->blocks_along_y()
    || this->_host->at(xto, yto)->type() == "BlockObstacle" || this->_host->at(xto, yto)->type() == "BlockSnakeBody") {
        this->_host->end_game();
    }
    // Натыкается на еду
    else if (this->_host->at(xto, yto)->type() == "BlockFood") {
        BlockFood* food = (BlockFood*)(this->_host->at(xto, yto));
        // Еда отравленная
        if (food->toxicity() > 0) {
            this->_host->shift(this->_snake_x[0], this->_snake_y[0], xto, yto);
            this->_host->shift(this->_snake_x[this->_snake_x.size() - 1], this->_snake_y[this->_snake_y.size() - 1],
                               this->_snake_x[0], this->_snake_y[0]);
            this->_snake_x.push_front(xto);
            this->_snake_y.push_front(yto);
            this->_snake_x.pop_back();
            this->_snake_y.pop_back();

            this->_host->end_game();
        }
        // Еда здоровая
        else {
            this->_host->shift(this->_snake_x[0], this->_snake_y[0], xto, yto);
            this->_host->place(this->_snake_x[0], this->_snake_y[0], new BlockSnakeBody);
            this->_snake_x.push_front(xto);
            this->_snake_y.push_front(yto);

            this->_host->spawn_food();
        }
    }
    // Пустой блок
    else {
        this->_host->shift(this->_snake_x[0], this->_snake_y[0], xto, yto);
        this->_host->shift(this->_snake_x[this->_snake_x.size() - 1], this->_snake_y[this->_snake_y.size() - 1],
                           this->_snake_x[0], this->_snake_y[0]);
        this->_snake_x.push_front(xto);
        this->_snake_y.push_front(yto);
        this->_snake_x.pop_back();
        this->_snake_y.pop_back();

        this->_wm->update(xto, yto);
    }
}

void Snake::connect_winding_manager(int food_x, int food_y, BlockFood *food)
{
    this->_wm->set(this->_snake_x[0], this->_snake_y[0], food_x, food_y, food);
}
