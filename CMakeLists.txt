cmake_minimum_required(VERSION 3.25)

project(Space_Duels
        VERSION 0.1.0
        LANGUAGES CXX
)

# -------------------------------
# C++ standard
# -------------------------------
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# -------------------------------
# Qt automatic tools
# -------------------------------
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# -------------------------------
# Generate version header
# -------------------------------
configure_file(
        ${CMAKE_SOURCE_DIR}/version.h.in
        ${CMAKE_BINARY_DIR}/generated/version.h
        @ONLY
)

# -------------------------------
# Dependencies
# -------------------------------
find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(Curses REQUIRED)

# -------------------------------
# Executable
# -------------------------------
add_executable(space_duels
        src/bots.cpp
        src/Card.cpp
        src/globals.cpp
        src/main.cpp
        src/Ship.cpp
        src/utils.cpp
        src/ShipView.cpp
        resources.qrc
)

set_target_properties(space_duels PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# -------------------------------
# Include directories
# -------------------------------
target_include_directories(space_duels
        PRIVATE
        ${CURSES_INCLUDE_DIR}
        ${CMAKE_BINARY_DIR}/generated
)

# -------------------------------
# Link libraries
# -------------------------------
target_link_libraries(space_duels
        PRIVATE
        Qt6::Widgets
        ${CURSES_LIBRARIES}
)

# -------------------------------
# Warnings (optional but recommended)
# -------------------------------

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(space_duels PRIVATE -Wall -Wextra -Wpedantic)
endif ()
