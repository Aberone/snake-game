#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    // ПРЕОБРАЗОВАНИЯ ОКОШКА ИГРОВОГО
    w.setFixedSize(w.blocks_along_x() * w.block_size_in_px(), w.blocks_along_y() * w.block_size_in_px());

    w.show();
    return a.exec();
}
