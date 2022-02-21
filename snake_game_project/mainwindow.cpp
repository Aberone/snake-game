#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "snake.h"

#include <QPainter>
#include <QPaintEvent>
#include <QKeyEvent>
#include <QTimer>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Место для подключения слотов
    QTimer* timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(move_snake()));
    timer->start(SNAKE_MOVEMENT_DELAY);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::blocks_along_x()
{
    return this->BLOCKS_ALONG_X;
}

int MainWindow::blocks_along_y()
{
    return this->BLOCKS_ALONG_Y;
}

int MainWindow::block_size_in_px()
{
    return this->BLOCK_SIZE_IN_PX;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    gamefield.draw(&painter);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Up) {
        gamefield.snake()->try_to_change_direction("up");
    }
    else if (event->key() == Qt::Key_Left) {
        gamefield.snake()->try_to_change_direction("left");
    }
    else if (event->key() == Qt::Key_Down) {
        gamefield.snake()->try_to_change_direction("down");
    }
    else if (event->key() == Qt::Key_Right) {
        gamefield.snake()->try_to_change_direction("right");
    }

    repaint();
}

void MainWindow::move_snake()
{
    gamefield.snake()->move();
    if (gamefield.game_over()) {
        QMessageBox msgbox;
        msgbox.setText("Game Over!");
        msgbox.exec();
        qApp->quit();
    }

    repaint();
}
