# Space_Duels
A card game that I invented and that I am starting to convert into a video game

## Note
This is currently in progress, and is in ultra - pre - alpha

## Compiling
To re-compile this, here is my recommended command using the gcc compiler:

<pre> g++ *.cpp -lncurses -o Space_Duels </pre>

Note that you also need to download the appropriate ncurses library for your OS  
And to run it:

<pre> ./Space_Duels </pre>

- The current Space_Duels executable is made for Linux (Crostini), not Windows or Mac

## Extra

Starting from version 0.0.4 you can use cmake instead of the g++ command, and Space_Duels executable was abandoned
and is no longer updated. The most recent compilation's .o files are in cmake-build-debug

My CLion configurations for cmake are stored in the .idea folder
