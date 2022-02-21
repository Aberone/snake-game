#include "windingmanager.h"
#include "blockfood.h"
#include <cmath>
//#include <QDebug>

WindingManager::WindingManager() {}

void WindingManager::set(int snake_x, int snake_y, int food_x, int food_y, BlockFood *food)
{
    this->_snake_x = snake_x;
    this->_snake_y = snake_y;
    this->_food_x = food_x;
    this->_food_y = food_y;
    this->_food = food;
    this->_angle = 0.0;

    //qDebug("Winding set!");
}

void WindingManager::update(int new_snake_x, int new_snake_y)
{
    double PI = 4*std::atan(1);
    double TWOPI = 8*std::atan(1);

    double angle1 = std::atan2(this->_snake_y - this->_food_y, this->_snake_x - this->_food_x);
    double angle2 = std::atan2(new_snake_y - this->_food_y, new_snake_x - this->_food_x);
    double delta = angle2 - angle1;
    if (delta > PI) {
        delta -= TWOPI;
    }
    else if (delta < -PI) {
        delta += TWOPI;
    }

    this->_angle += delta;
    if (this->_angle > TWOPI) {
        this->_angle -= TWOPI;
    }
    else if (this->_angle < -TWOPI) {
        this->_food->healthify();
        this->_angle += TWOPI;
    }

    this->_snake_x = new_snake_x;
    this->_snake_y = new_snake_y;
    //qDebug("Accumulated angle: %f", this->_angle);
}


