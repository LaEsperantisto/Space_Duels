
#include "init_ncurses.h"

void init_ncurses() {
    initscr();

    raw();
    noecho();
    curs_set(1);
    cbreak();
}
