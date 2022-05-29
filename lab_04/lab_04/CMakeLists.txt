cmake_minimum_required(VERSION 3.21)
project(lab_04_oop)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "C:/Qt/6.2.4/mingw_64/lib/cmake")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED
        )

add_executable(lab_04_oop
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        Doors.cpp Doors.h Cabin.cpp Cabin.h Controller.cpp Controller.h Elevator.cpp Elevator.h)

target_link_libraries(lab_04_oop
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )
