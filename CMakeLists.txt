cmake_minimum_required(VERSION 3.25)
project(versions/Space_Duels-0.0.4/Space_Duels)

set(CMAKE_CXX_STANDARD 20)

set(version "0.0.4")

file(GLOB all_cpp
        "versions/Space_Duels-${version}/*.cpp"
)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(main
        ${all_cpp}
)

target_link_libraries(main ${CURSES_LIBRARIES})
