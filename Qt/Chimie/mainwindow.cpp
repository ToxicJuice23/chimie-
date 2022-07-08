#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "chimie/define.cpp"
#include <vector>

string exec(const char* cmd) {
    array<char, 128> buffer;
    string result;
    unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

// Init function of the app
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    Chimie::Init();
    ui->setupUi(this);
    bg_color = "#6B5B95";
    ui->elementInput->setPlaceholderText("Entre un nom d'un élément ici");
    ui->elementInput_2->setPlaceholderText("Entre un nom d'un élément ici");
    string buttonStyle = "background-color: #edebeb; color: "+bg_color+";";
    ui->pushButton->setStyleSheet(buttonStyle.c_str());
    ui->pushButton_2->setStyleSheet(buttonStyle.c_str());
    ui->pushButton_3->setStyleSheet(buttonStyle.c_str());
    ui->pushButton_4->setStyleSheet(buttonStyle.c_str());
    ui->pushButton_5->setStyleSheet(buttonStyle.c_str());
    ui->pushButton_6->setStyleSheet(buttonStyle.c_str());
    ui->pushButton_7->setStyleSheet((buttonStyle + "font-size: 15px;").c_str());
    ui->pushButton_8->setStyleSheet(buttonStyle.c_str());
    ui->pushButton_9->setStyleSheet((buttonStyle + "font-size: 15px;").c_str());
    ui->elementInput->setStyleSheet((buttonStyle + "font-size: 15px;").c_str());
    ui->elementInput_2->setStyleSheet((buttonStyle + "font-size: 15px;").c_str());
    string total_values;
    for (Element* element : all) {
        if (element == all[0]) continue;
        vector<string> result = Chimie::getValues(element);
        string final;
        string order[10] = {"Nom de l'élément: ", "Symbole atomique: ", "Numero atomique: ", "Nombre d'électrons: ", "Nombre de protons: ", "Nombre de neutrons: ", "Charge de l'élément: ", "Nombre d'éléctrons de valence: ", "Masse atomique: ", "Est un métal: "};
        int index = 0;
        for (string value : result) {
            if (index != 9) {
                final.append(order[index] + value + "\n");
            } else {
                final.append(order[index] + Chimie::boolToFrench(stoi(value)) + "\n");
            }
            index++;
        }
        total_values.append(final + "\n\n\n");
    }
    ui->elementList->setText(total_values.c_str());
    ui->sideBar->setSpacing(0);
    ui->sideBarWidget->setStyleSheet("background-color: #251f33");
    ui->pushButton_15->setStyleSheet("color: lightcoral;");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    exit(0);
}


void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    setWindowTitle("Chimie++ | Recherche");
}


void MainWindow::on_pushButton_7_clicked()
{
    Element* element = Chimie::findElementByName(ui->elementInput->text().toStdString());
    if (element) {
        vector<string> result = Chimie::getValues(element);
        string final;
        string order[10] = {"Nom de l'élément: ", "Symbole atomique: ", "Numero atomique: ", "Nombre d'électrons: ", "Nombre de protons: ", "Nombre de neutrons: ", "Charge de l'élément: ", "Nombre d'éléctrons de valence: ", "Masse atomique: ", "Est un métal: "};
        int index = 0;
        for (string value : result) {
            if (index != 9) {
                final.append(order[index] + value + "\n");
            } else {
                final.append(order[index] + Chimie::boolToFrench(stoi(value)) + "\n");
            }
            index++;
        }
        ui->elementInfo->setText(final.c_str());
    } else {
        ui->elementInfo->setText("Incapable de trouver l'élément.");
    }
}


void MainWindow::on_elementInput_returnPressed()
{
    Element* element = Chimie::findElementByName(ui->elementInput->text().toStdString());
    if (element) {
        vector<string> result = Chimie::getValues(element);
        string final;
        string order[10] = {"Nom de l'élément: ", "Symbole atomique: ", "Numero atomique: ", "Nombre d'électrons: ", "Nombre de protons: ", "Nombre de neutrons: ", "Charge de l'élément: ", "Nombre d'éléctrons de valence: ", "Masse atomique: ", "Est un métal: "};
        int index = 0;
        for (string value : result) {
            if (index != 9) {
                final.append(order[index] + value + "\n");
            } else {
                final.append(order[index] + Chimie::boolToFrench(stoi(value)) + "\n");
            }
            index++;
        }
        ui->elementInfo->setText(final.c_str());
    } else {
        ui->elementInfo->setText("Incapable de trouver l'élément.");
    }
}


void MainWindow::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    setWindowTitle("Chimie++ | Acceuil");
}


void MainWindow::on_pushButton_5_clicked()
{
    setWindowTitle("Chimie++ | Gaz Inerte");
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_pushButton_9_clicked() // confirm button for gaz inerte
{
    string result = ui->elementInput_2->text().toStdString();
    Element* element = Chimie::findElementByName(result);
    if (element) {
        Element* gi_proche = element->trouver_gi_proche();
        vector<string> values = Chimie::getValues(gi_proche);
        string final;
        string order[10] = {"Nom de l'élément: ", "Symbole atomique: ", "Numero atomique: ", "Nombre d'électrons: ", "Nombre de protons: ", "Nombre de neutrons: ", "Charge de l'élément: ", "Nombre d'éléctrons de valence: ", "Masse atomique: ", "Est un métal: "};
        int index = 0;
        for (string value : values) {
            if (index != 9) {
                final.append(order[index] + value+" \n");
            } else {
                final.append(order[index] + Chimie::boolToFrench(stoi(value)) + "\n");
            }
            index++;
        }
        ui->elementInfo_2->setText(final.c_str());
    } else {
        ui->elementInfo_2->setText("Incapable de trouver l'élément.");
    }
}


void MainWindow::on_elementInput_2_returnPressed()
{
    on_pushButton_9_clicked();
}


void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    setWindowTitle("Chimie | Tout les éléments");
}


void MainWindow::on_pushButton_11_clicked()
{
    on_pushButton_6_clicked();
}


void MainWindow::on_pushButton_12_clicked()
{
    on_pushButton_5_clicked();
}


void MainWindow::on_pushButton_3_clicked()
{

}


void MainWindow::on_pushButton_13_clicked()
{
    on_pushButton_3_clicked();
}


void MainWindow::on_pushButton_14_clicked()
{
    on_pushButton_4_clicked();
}


void MainWindow::on_pushButton_15_clicked()
{
    on_pushButton_clicked();
}


void MainWindow::on_pushButton_16_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

