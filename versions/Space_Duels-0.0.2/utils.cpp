#include "utils.h"

#include <ncurses.h>
#include <algorithm>

#include "Ship.h"
#include "globals.h"

int middle_offset(Ship ship1, Ship ship2) {
    return std::max(ship1.get_width() - ship1.get_alignment_index(),
        ship2.get_width() - ship2.get_alignment_index());
}

void print_ships(Ship ship1, Ship ship2) {
    int offset = middle_offset(ship1, ship2);

    auto s1 = ship1.getCards();
    auto s2 = ship2.getCards();

    for (int x = 0; x < s1.size(); x++) {
        for (int y = 0; y < s1.at(x).size(); y++) {
            auto card = s1.at(x).at(y);
            if (!card->isEmpty())
                mvprintw(y * card_height,
                    (x + offset) * card_width,
                    "%s power: %d rank: %d",
                    card->get_short_name().c_str(),
                    card->get_power(),
                    card->get_rank()
                );
        }
    }

    for (int x = 0; x < s2.size(); x++) {
        for (int y = 0; y < s2.at(x).size(); y++) {
            auto card = s2.at(x).at(ship2.get_height() - 1 - y);
            if (!card->isEmpty())
                mvprintw((y + gap_between_ships) * card_height + ship1.get_height() * card_height,
                    (x + offset) * card_width,
                    "%s power: %d rank: %d",
                    card->get_short_name().c_str(),
                    card->get_power(),
                    card->get_rank()
                );
        }
    }
}

