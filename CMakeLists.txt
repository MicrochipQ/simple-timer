cmake_minimum_required(VERSION 3.21)
project(cpp_timer)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

file(GLOB cpp_timer_SRC src/*.cpp src/*.h)

add_executable(cpp_timer ${cpp_timer_SRC})

target_link_libraries(cpp_timer PRIVATE Qt5::Widgets)
