cmake_minimum_required(VERSION 3.16)
project(EngJOYTests)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(EngJOY_tests tests.cpp)

target_sources(EngJOY_tests PRIVATE
    ../card.cpp
    ../filemanager.cpp
)

target_include_directories(EngJOY_tests PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/..
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(EngJOY_tests Qt${QT_VERSION_MAJOR}::Core)

add_test(NAME EngJOY_tests COMMAND EngJOY_tests)
