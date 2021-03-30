# задаем набор исходников
set(SOURCES
Task1.1.cpp
)

# создаем статическую библиотеку
add_library(sq_lib ${SOURCES})

# добавлем путь к исходникам для возожности подключения библиотеки
target_include_directories(sq_lib PUBLIC ${SRC_ROOT_DIR})

# группируем исходники по типу по категориям
source_group(TREE ${CMAKE_CURRENT_LIST_DIR} FILES ${SOURCES})

# В solution эта библиотека лежит в test_project
set_property(TARGET sq_lib PROPERTY FOLDER "test_project")

# включаем в сборку проекnа подпроект с тестами
add_subdirectory(tests)
