cmake_minimum_required(VERSION 3.16)

project(EngJOY VERSION 0.1 LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets)
qt_standard_project_setup()

qt_add_executable(EngJOY
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
)

target_link_libraries(EngJOY PRIVATE Qt6::Core Qt6::Widgets)

if(WIN32)
    set_target_properties(EngJOY PROPERTIES WIN32_EXECUTABLE TRUE)
    get_target_property(QMAKE_EXECUTABLE Qt6::qmake IMPORTED_LOCATION)
    get_filename_component(QT_BIN_DIR "${QMAKE_EXECUTABLE}" DIRECTORY)
    find_program(WINDEPLOYQT_EXECUTABLE windeployqt HINTS "${QT_BIN_DIR}")

    if(WINDEPLOYQT_EXECUTABLE)
        add_custom_command(TARGET EngJOY POST_BUILD
            COMMAND "${WINDEPLOYQT_EXECUTABLE}" "$<TARGET_FILE:EngJOY>" --verbose 0
        )
    endif()
endif()
