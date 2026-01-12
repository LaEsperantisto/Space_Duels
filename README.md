# Space Duels

**Space Duels** is a strategy card game I originally invented as a tabletop concept and am now actively converting
into a video game using **C++ and Qt**.

The game focuses on tactical ship layouts, card-based combat, and head-to-head duels between opposing spaceships.

---

## Project Status

**Ultra pre-alpha**

This project is very early in development.  
Core mechanics, rendering, and architecture are still evolving, and breaking changes should be expected.

At this stage:

- Gameplay is incomplete
- Assets are placeholder
- APIs and file structure are not stable

---

## Technologies

- Language: C++
- Framework: Qt 6 (Widgets)
- Rendering: Custom Qt-based drawing
- Original UI: ncurses (now being migrated to Qt)

---

## Dependencies

- Qt 6  
  Required modules:
    - Qt6::Widgets
    - Qt6::Gui
    - Qt6::Core

The project is intended to be cross-platform and should build on:

- Linux
- Windows
- macOS

(Tested primarily on Linux at the moment.)

---

## Building (early outline)

Build instructions may change frequently, but a typical CMake-based setup may look like this:

```bash
mkdir build
cd build
cmake ..
make
```

## Complete Guide

Go to https://space-duels.fandom.com/wiki/Space_Duels_Wiki for the complete guide.
