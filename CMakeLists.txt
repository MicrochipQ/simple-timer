cmake_minimum_required(VERSION 3.21)
project(simple_timer)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

file(GLOB simple_timer_SRC src/*.cpp src/*.h)

add_executable(simple_timer ${simple_timer_SRC})

target_link_libraries(simple_timer PRIVATE Qt5::Widgets)
