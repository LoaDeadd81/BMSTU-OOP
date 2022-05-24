#include "qt_files/mainwindow.h"
#include "Solution.h"
#include "Creator.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    ModelBuilderSolution mb_sol;
    CameraBuilderSolution cb_sol;
    ModelDirectorSolution md_sol;
    CameraDirectorSolution cd_sol;
    LoaderSolution load_sol;
    FabricSolution fab_sol;

    mb_sol.registeraation("frame", make_shared<ModelBuilderCreator>());
    mb_sol.configure("frame");

    cb_sol.registeraation("camera", make_shared<CameraBuilderCreator>());
    cb_sol.configure("camera");

    md_sol.registeraation("frame", make_shared<ModelDirectorCreator>());
    md_sol.configure("frame");

    cd_sol.registeraation("camera", make_shared<CameraDirectorCreator>());
    cd_sol.configure("camera");

    load_sol.registeraation("txt", make_shared<TXTLoaderCreator>());
    load_sol.configure("txt");

    fab_sol.registeraation("qt", make_shared<QtFabricCreator>());
    fab_sol.configure("qt");

    QApplication a(argc, argv);
    MainWindow w;
    w.showMaximized();
    w.show();
    return a.exec();
}
