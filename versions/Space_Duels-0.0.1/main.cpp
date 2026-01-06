#include <ncurses.h>

#include <string>
#include <iostream>

#include "utils.h"
#include "bots.h"
#include "init_ncurses.h"

// TODO:
/*

Fix displaying cards' power

*/

int main(int argc, char* argv[]) {

    init_ncurses();

    // print_ships(bot0, bot1);
    print_ships(bot2, bot3);

    refresh();
    getch();
    endwin();
}