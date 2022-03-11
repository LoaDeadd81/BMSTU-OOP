#include "mainwindow.h"
#include "ui_mainwindow.h"

//double checked_read(QLineEdit *lineEdit1);

//void show_error(QString title, QString message);

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


//double checked_read(QLineEdit *lineEdit1)
//{
//    bool e1 = true;
//    lineEdit1->setStyleSheet("");
//     double x = lineEdit1->text().toDouble(&e1);
//    if (!e1)
//    {
//        lineEdit1->setStyleSheet("border: 1px solid red");
//        throw InputError("");
//    }
//    return x;
//}

//void show_error(QString title, QString message)
//{
//    QErrorMessage error_msg;
//    error_msg.setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
//    error_msg.setStyleSheet("QLabel{min-height: 100px; font-size: 100px;}");
//    error_msg.showMessage(message);
//    error_msg.setWindowTitle(title);
//    QFont font;
//    font.setPointSize(14);
//    error_msg.setFont(font);
//    error_msg.exec();
//}





