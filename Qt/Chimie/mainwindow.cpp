#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    bg_color = "#3b3b3b";
}

MainWindow::~MainWindow()
{
    delete ui;
}

