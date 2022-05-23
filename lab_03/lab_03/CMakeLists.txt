cmake_minimum_required(VERSION 3.16)
project(lab_03_qt)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_PREFIX_PATH "C:/Qt/6.2.4/mingw_64/lib/cmake")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_VERSION 6)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt6::Core Qt6::Gui Qt6::Widgets)

include_directories(objects
        model
        scene
        camera
        visitor
        commands
        managers
        creators
        draw
        build
        solution
        )

add_executable(${PROJECT_NAME}
        main.cpp
        qt_files/mainwindow.h
        qt_files/mainwindow.cpp
        qt_files/mainwindow.ui
        objects/SceneObjects.h model/Model.cpp model/Model.h model/primitives.cpp model/primitives.h model/Coord.cpp model/Coord.h camera/Camera.cpp camera/Camera.h visitor/ObjectVisitor.h objects/SimpleObject.h objects/CompositeObject.cpp objects/CompositeObject.h visitor/TransformVisitor.cpp visitor/TransformVisitor.h scene/Scene.cpp scene/Scene.h scene/BaseScene.h scene/SceneInterface.h commands/BaseCommand.h commands/Commands.cpp commands/Commands.h managers/BaseManager.h managers/Managers.cpp managers/Managers.h creators/CommandCreators.h creators/CommandCreators.cpp creators/VisitorCreators.cpp creators/VisitorCreators.h draw/Drawer.cpp draw/Drawer.h draw/DrawTools.h draw/QtDrawTools.cpp draw/QtDrawTools.h creators/QtToolCreators.cpp creators/QtToolCreators.h visitor/DrawVisitor.cpp visitor/DrawVisitor.h build/Loader.cpp build/Loader.h build/Builder.cpp build/Builder.h creators/FabricCreator.cpp creators/FabricCreator.h solution/FabricSolution.cpp solution/FabricSolution.h)

#if (NOT CMAKE_PREFIX_PATH)
#    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
#            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
#endif ()


find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})
