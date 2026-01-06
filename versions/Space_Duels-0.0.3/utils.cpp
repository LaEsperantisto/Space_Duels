#include "utils.h"

// #include <iostream>
#include <ncurses.h>

#include "Ship.h"
#include "globals.h"

void print_ships(const Ship &ship1, const Ship &ship2) {
    const auto [fst, snd] = align_ships(ship1, ship2);

    const auto &s1 = fst.get_cards();
    const auto &s2 = snd.get_cards();

    for (int x = 0; x < s1.size(); x++) {
        for (int y = 0; y < s1.at(x).size(); y++) {
            if (const auto &card = s1.at(x).at(y); !card->isEmpty())
                mvprintw(y * card_height,
                         x * card_width,
                         "%s power: %d rank: %d",
                         card->get_short_name().c_str(),
                         card->get_power(),
                         card->get_rank()
                );
        }
    }

    for (int x = 0; x < s2.size(); x++) {
        for (int y = 0; y < s2.at(x).size(); y++) {
            if (const auto &card = s2.at(x).at(ship2.get_height() - 1 - y); !card->isEmpty())
                mvprintw((y + gap_between_ships) * card_height + ship1.get_height() * card_height, x * card_width,
                         "%s power: %d rank: %d",
                         card->get_short_name().c_str(),
                         card->get_power(),
                         card->get_rank()
                );
        }
    }
}

std::vector<CardPtr> make_blank_column(const int height) {
    std::vector<CardPtr> col;
    col.reserve(height);

    for (int i = 0; i < height; ++i)
        col.push_back(std::make_unique<Empty>());

    return col;
}

std::pair<Ship, Ship> align_ships(Ship ship1, Ship ship2) {
    int align_1 = ship1.get_alignment_index();
    int align_2 = ship2.get_alignment_index();

    auto s1 = ship1.get_cards();
    auto s2 = ship2.get_cards();

    while (align_1 != align_2) {
        if (align_1 > align_2) {
            s2.insert(s2.begin(), make_blank_column(ship2.get_height()));
            ship2.set_cards(s2);
            align_2 = ship2.get_alignment_index();
        } else {
            s1.insert(s1.begin(), make_blank_column(ship1.get_height()));
            ship1.set_cards(s1);
            align_1 = ship1.get_alignment_index();
        }
    }

    return {ship1, ship2};
}
