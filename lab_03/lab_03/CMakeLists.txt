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
        )

add_executable(${PROJECT_NAME}
        main.cpp
        qt_files/mainwindow.h
        qt_files/mainwindow.cpp
        qt_files/mainwindow.ui
        scene/SceneInterface.cpp
        scene/SceneInterface.h
        scene/Scene.cpp
        scene/Scene.h
        objects/Objects.cpp
        objects/Objects.h objects/VisibleObjects.h model/Model.cpp model/Model.h model/primitives.cpp model/primitives.h model/Coord.cpp model/Coord.h objects/InvisibleObject.h camera/Camera.cpp camera/Camera.h visitor/ObjectVisitor.h visitor/TransformVisitor.cpp visitor/TransformVisitor.h)

#if (NOT CMAKE_PREFIX_PATH)
#    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
#            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
#endif ()


find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})
