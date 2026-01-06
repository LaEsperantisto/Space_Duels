cmake_minimum_required(VERSION 3.25)
project(Space_Duels)

set(CMAKE_CXX_STANDARD 20)

set(version "0.0.4")

file(GLOB all_cpp
        "versions/Space_Duels-${version}/*.cpp"
)

add_executable(main
        ${all_cpp}
)
