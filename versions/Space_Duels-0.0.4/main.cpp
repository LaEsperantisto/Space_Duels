#include <ncurses.h>

// #include <string>
// #include <iostream>

#include "utils.h"
#include "bots.h"
#include "init_ncurses.h"

// TODO:
/*
 *
 *
 *
*/

int main(const int argc, const char *argv[]) {
    init_ncurses();

    // print_ships(bot3, bot1);
    print_ships(bot2, bot3);

    refresh();
    getch();
    endwin();
    return 0;
}
