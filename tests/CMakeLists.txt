cmake_minimum_required(VERSION 3.16)
project(EngJOYTests)

# Находим Qt (но для тестов он может не понадобиться)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

# Добавляем тестовый исполняемый файл
add_executable(EngJOY_tests tests.cpp)

# Подключаем исходные файлы из основного проекта
target_sources(EngJOY_tests PRIVATE
    ../card.cpp
    ../filemanager.cpp
)

# Указываем включаемые директории
target_include_directories(EngJOY_tests PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/..
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Подключаем Qt Core если нужно
target_link_libraries(EngJOY_tests Qt${QT_VERSION_MAJOR}::Core)

# Добавляем цель тестирования
add_test(NAME EngJOY_tests COMMAND EngJOY_tests)