#include "mainwindow.h"
#include "ui_mainwindow.h"

int checked_read(QLineEdit *lineEdit1, double &res);

void error_handle(error_code rc);

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    QRect rect = ui->ResView->geometry();
//    scene = new QGraphicsScene(0, 0, rect.width(), rect.height(), this);
//    ui->ResView->setScene(scene);

    scene = new QGraphicsScene(this);
    ui->ResView->setScene(scene);
    ui->ResView->setAlignment(Qt::AlignCenter);
    scene->setSceneRect(0, 0, 1, 1);
    is_exist = false;
}

MainWindow::~MainWindow()
{
    request main_request = {DEL};
    do_request(main_request);
    delete ui;
}

void MainWindow::on_GetDataButton_clicked()
{
    error_code rc = do_read_request();
    if (rc != SUCCESS)
        error_handle(rc);
    else
    {
        do_draw_request();
        is_exist = true;
    }
}

void MainWindow::on_MoveButton_clicked()
{
    error_code rc = SUCCESS;
    if(is_exist)
        rc = do_move_request();
    else
        rc = MODEL_INIT_ERROR;
    if (rc != SUCCESS)
        error_handle(rc);
    else
        do_draw_request();
}


void MainWindow::on_ScaleButton_clicked()
{
    error_code rc = SUCCESS;
    if(is_exist)
        rc = do_scale_request();
    else
        rc = MODEL_INIT_ERROR;
    if (rc != SUCCESS)
        error_handle(rc);
    else
        do_draw_request();
}


void MainWindow::on_RotateButton_clicked()
{
    error_code rc = SUCCESS;
    if(is_exist)
        rc = do_rotate_request();
    else
        rc = MODEL_INIT_ERROR;
    if (rc != SUCCESS)
        error_handle(rc);
    else
        do_draw_request();
}

error_code MainWindow::do_read_request()
{
    QString file_name = ui->FileNameLineEdit->text();
    std::string file_name_str = file_name.toStdString();

    request main_request = {INPUT};
    main_request.read = {file_name_str.c_str()};

    error_code rc = do_request(main_request);
    return rc;
}

error_code MainWindow::do_draw_request()
{
    request main_request = {DRAW};
    main_request.draw.scene = scene;

    error_code rc = do_request(main_request);
    return rc;
}

error_code MainWindow::do_move_request()
{
    error_code rc = SUCCESS;
    double dx, dy, dz;
    int inp_status = 0;
    inp_status += checked_read(ui->dxLineEdit, dx);
    inp_status += checked_read(ui->dyLineEdit, dy);
    inp_status += checked_read(ui->dzLineEdit, dz);
    if (inp_status > 0)
        rc = DATA_ERROR;
    else
    {
        request main_request = {MOVE};
        main_request.move = {dx, dy, dz};

        rc = do_request(main_request);
    }
    return rc;
}

error_code MainWindow::do_scale_request()
{
    error_code rc = SUCCESS;
    double kx, ky, kz;
    point_type center;
    int inp_status = 0;
    inp_status += checked_read(ui->kxLineEdit, kx);
    inp_status += checked_read(ui->kyLineEdit, ky);
    inp_status += checked_read(ui->kzLineEdit, kz);
    rc = get_center(center);
    if (inp_status > 0 || rc != SUCCESS)
        rc = DATA_ERROR;
    else
    {
        request main_request = {SCALE};
        main_request.scale = {center, {kx, ky, kz}};

        rc = do_request(main_request);
    }
    return rc;
}

error_code MainWindow::do_rotate_request()
{
    error_code rc = SUCCESS;
    double cx, cy, cz;
    point_type center;
    int inp_status = 0;
    inp_status += checked_read(ui->cxLineEdit, cx);
    inp_status += checked_read(ui->cyLineEdit, cy);
    inp_status += checked_read(ui->czLineEdit, cz);
    rc = get_center(center);
    if (inp_status > 0 || rc != SUCCESS)
        rc = DATA_ERROR;
    else
    {
        request main_request = {ROTATE};
        main_request.rotate = {center, {cx, cy, cz}};

        rc = do_request(main_request);
    }
    return rc;
}

error_code MainWindow::get_center(point_type &center)
{
    error_code rc = SUCCESS;
    double x, y, z;
    int inp_status = 0;
    inp_status += checked_read(ui->xLineEdit, x);
    inp_status += checked_read(ui->yLineEdit, y);
    inp_status += checked_read(ui->zLineEdit, z);
    if (inp_status > 0)
        rc = DATA_ERROR;
    else
        center = {x, y, z};
    return rc;
}

void error_handle(error_code rc)
{
    QErrorMessage error_window;
    QString message = error_interpretation(rc);
    error_window.showMessage(message);
    error_window.setWindowTitle("Ошибка");
    error_window.exec();
}

int checked_read(QLineEdit *lineEdit1, double &res)
{
    bool e1 = true;
    lineEdit1->setStyleSheet("");
    res = lineEdit1->text().toDouble(&e1);
    if (!e1)
    {
        lineEdit1->setStyleSheet("border: 1px solid red");
        return 1;
    }
    return 0;
}


