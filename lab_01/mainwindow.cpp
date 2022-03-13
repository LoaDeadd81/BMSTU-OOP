#include "mainwindow.h"
#include "ui_mainwindow.h"

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
        do_draw_request();
}

void MainWindow::on_MoveButton_clicked()
{
    error_code rc = do_move_request();
    if (rc != SUCCESS)
        error_handle(rc);
    else
        do_draw_request();
}


void MainWindow::on_ScaleButton_clicked()
{
    error_code rc = do_scale_request();
    if (rc != SUCCESS)
        error_handle(rc);
    else
        do_draw_request();
}


void MainWindow::on_RotateButton_clicked()
{
    error_code rc = do_rotate_request();
    if (rc != SUCCESS)
        error_handle(rc);
    else
        do_draw_request();
}

error_code MainWindow::do_read_request()
{
    QString file_name = ui->FileNameLineEdit->text();
    std::string file_name_str = file_name.toStdString();

    request main_request = {READ_DATA};
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
    double dx = ui->dxLineEdit->text().toDouble(),
            dy = ui->dyLineEdit->text().toDouble(),
            dz = ui->dzLineEdit->text().toDouble();

    request main_request = {MOVE};
    main_request.move = {dx, dy, dz};

    error_code rc = do_request(main_request);
    return rc;
}

error_code MainWindow::do_scale_request()
{
    double kx = ui->kxLineEdit->text().toDouble(),
            ky = ui->kyLineEdit->text().toDouble(),
            kz = ui->kzLineEdit->text().toDouble();
    point center;
    error_code rc = get_center(center);
    if (rc == SUCCESS)
    {
        request main_request = {SCALE};
        main_request.scale = {center, kx, ky, kz};

        rc = do_request(main_request);
    }
    return rc;
}

error_code MainWindow::do_rotate_request()
{
    double cx = ui->cxLineEdit->text().toDouble(),
            cy = ui->cyLineEdit->text().toDouble(),
            cz = ui->czLineEdit->text().toDouble();
    point center;
    error_code rc = get_center(center);
    if (rc == SUCCESS)
    {
        request main_request = {ROTATE,};
        main_request.rotate = {center, cx, cy,  cz};

        rc = do_request(main_request);
    }
    return rc;
}

error_code MainWindow::get_center(point &center)
{
    double x = ui->xLineEdit->text().toDouble(),
            y = ui->yLineEdit->text().toDouble(),
            z = ui->zLineEdit->text().toDouble();
    center = {x, y, z};
    return SUCCESS;
}

void error_handle(error_code rc)
{
    QErrorMessage error_window;
    QString message = error_interpretation(rc);
    error_window.showMessage(message);
    error_window.setWindowTitle("Ошибка");
    error_window.exec();
}



