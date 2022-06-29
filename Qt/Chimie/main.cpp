#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon("./chimieLogo.ico"));
    MainWindow w;
    w.resize(800, 600);
    w.setWindowTitle("Chimie++");
    w.show();
    w.setStyleSheet(("background-color:"+w.bg_color+";color:white;").c_str());
    return a.exec();
}
