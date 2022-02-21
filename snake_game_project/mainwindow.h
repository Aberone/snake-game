#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gamefield.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int blocks_along_x();
    int blocks_along_y();
    int block_size_in_px();

    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);

public slots:
    void move_snake();

private:
    Ui::MainWindow *ui;

    // Глобальные переменные
    int BLOCKS_ALONG_X = 25;
    int BLOCKS_ALONG_Y = 25;
    int BLOCK_SIZE_IN_PX = 20;
    int OBSTACLES_ACCOUNT = 20;
    int SNAKE_MOVEMENT_DELAY = 500;
    GameField gamefield = GameField(BLOCKS_ALONG_X, BLOCKS_ALONG_Y, BLOCK_SIZE_IN_PX, OBSTACLES_ACCOUNT);
};
#endif // MAINWINDOW_H
