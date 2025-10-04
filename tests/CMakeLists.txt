find_package(Qt6 REQUIRED COMPONENTS Core Widgets Test)

add_library(doctest INTERFACE)
target_include_directories(doctest INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

add_library(card_lib ../card.cpp)
add_library(filemanager_lib ../filemanager.cpp)

#Сами тесты
add_executable(card_tests card_tests.cpp)
target_link_libraries(card_tests PRIVATE doctest card_lib)
add_test(NAME CardTests COMMAND card_tests)

add_executable(randomcard_tests randomcard_tests.cpp)
target_link_libraries(randomcard_tests PRIVATE doctest filemanager_lib card_lib)
add_test(NAME RandomCardTests COMMAND randomcard_tests)

add_executable(filemanager_tests filemanager_tests.cpp)
target_link_libraries(filemanager_tests PRIVATE doctest filemanager_lib card_lib)
add_test(NAME FileManagerTests COMMAND filemanager_tests)

