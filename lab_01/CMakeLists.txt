cmake_minimum_required(VERSION 3.16)
project(lab_02)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "C:\\Qt\\6.2.3\\mingw_64\\lib\\cmake\\")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(lab_01
        lab_01.pro
        lab_01.pro.user
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        Request.cpp Request.h ErrorType.cpp ErrorType.h FrameModel.cpp FrameModel.h Edge.cpp Edge.h Point.cpp Point.h draw.cpp draw.h io.cpp io.h transform.cpp transform.h)

target_link_libraries(lab_01
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

include_directories(./inc)

