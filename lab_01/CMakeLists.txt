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
        request.cpp request.h point.h line.h model_io.cpp model_io.h model.cpp model.h draw.cpp draw.h transformation.cpp transformation.h erorrs.cpp erorrs.h point.cpp line.cpp)

target_link_libraries(lab_01
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

include_directories(./inc)

