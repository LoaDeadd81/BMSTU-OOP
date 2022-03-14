#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QPen>
#include <QRect>
#include <QErrorMessage>
#include <QString>
#include <string>

#include "request.h"
#include "erorrs.h"
#include "point.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_GetDataButton_clicked();

//    void on_SelectCenterButton_clicked();

    void on_MoveButton_clicked();

    void on_ScaleButton_clicked();

    void on_RotateButton_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    bool is_exist;
    error_code do_read_request();
    error_code do_draw_request();
    error_code do_move_request();
    error_code do_scale_request();
    error_code do_rotate_request();
    error_code get_center(point &center);
};
#endif
