cmake_minimum_required(VERSION 3.16)

project(EngJOY VERSION 0.1 LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets)
qt_standard_project_setup()

# Создаем библиотеку вместо исполняемого файла
qt_add_library(EngJOY STATIC
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    card.cpp
    card.h
    deckeditor.cpp
    deckeditor.h
    deckeditor.ui
    learnmode.cpp
    learnmode.h
    learnmode.ui
    testmode.cpp
    testmode.h
    testmode.ui
    filemanager.cpp
    filemanager.h
    tests/tests.cpp

)

target_link_libraries(EngJOY Qt6::Core Qt6::Widgets)
