cmake_minimum_required(VERSION 3.25)

project(Space_Duels
        VERSION 0.0.5
        LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Generate version header
configure_file(
        ${CMAKE_SOURCE_DIR}/version.h.in
        ${CMAKE_BINARY_DIR}/generated/version.h
        @ONLY
)

# Source files
file(GLOB all_cpp
        "${CMAKE_SOURCE_DIR}/src/*.cpp"
)

find_package(Curses REQUIRED)

add_executable(space_duels
        ${all_cpp}
)

target_link_libraries(space_duels PRIVATE ${CURSES_LIBRARIES})
target_include_directories(space_duels PRIVATE
        ${CURSES_INCLUDE_DIR}
        ${CMAKE_BINARY_DIR}/generated
)
