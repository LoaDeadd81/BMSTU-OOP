#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) , ui(new Ui::MainWindow), elevator(this)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_9_clicked()
{
    cout << "Was clicked Button 9 on lift controller." << endl;
    elevator.call(9);
}

void MainWindow::on_pushButton_8_clicked()
{
    cout << "Was clicked Button 7 on lift controller." << endl;
    elevator.call(7);
}

void MainWindow::on_pushButton_7_clicked()
{
    cout << "Was clicked Button 8 on lift controller." << endl;
    elevator.call(8);
}

void MainWindow::on_pushButton_6_clicked()
{
    cout << "Was clicked Button 6 on lift controller." << endl;
    elevator.call(6);
}


void MainWindow::on_pushButton_5_clicked()
{
    cout << "Was clicked Button 5 on lift controller." << endl;
    elevator.call(5);
}


void MainWindow::on_pushButton_4_clicked()
{
    cout << "Was clicked Button 4 on lift controller." << endl;
    elevator.call(4);
}


void MainWindow::on_pushButton_3_clicked()
{
    cout << "Was clicked Button 3 on lift controller." << endl;
    elevator.call(3);
}


void MainWindow::on_pushButton_2_clicked()
{
    cout << "Was clicked Button 2 on lift controller." << endl;
    elevator.call(2);
}


void MainWindow::on_pushButton_1_clicked()
{
    cout << "Was clicked Button 1 on lift controller." << endl;
    elevator.call(1);
}

