#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTabWidget>
#include <QMessageBox>
#include <iostream>
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    string bg_color;
    string compose_element_1;
    string compose_element_2;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_elementInput_returnPressed();

    void on_pushButton_8_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_9_clicked();

    void on_elementInput_2_returnPressed();

    void on_pushButton_4_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_10_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
