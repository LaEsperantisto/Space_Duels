#include "Ship.h"

#include <stdexcept>

Ship::Ship(CardVec2D cards) : cards(cards) {
    init_hub_count();
}

Ship::Ship(CardInitList2D init) {
    cards.reserve(init.size());

    int expected_width = 0;

    for (auto row : init) {
        if (expected_width == 0)
            expected_width = row.size();
        else if (row.size() != expected_width)
            throw std::runtime_error("Ship card layout must be rectangular");

        cards.emplace_back(row.begin(), row.end());
    }

    init_hub_count();
}

CardVec2D Ship::getCards() {
    return cards;
}

bool Ship::isHub(const Card& card) {
    return card.get_name() == "Hub";
}

void Ship::init_hub_count() {
    for (int x = 0; x < this->cards.size(); ++x) {
        for (const Card& card : this->cards[x]) {
            if (isHub(card)) {
                num_hubs++;

                if (num_hubs == 1) {
                    alignment_index = static_cast<int>(x);
                } else {
                    isLegal = false;
                    throw std::runtime_error("Ship may only contain one Hub");
                }
            }
        }
    }
}

int Ship::get_alignment_index() {
    return alignment_index;
}

int Ship::get_width() {
    return cards.size();
}

int Ship::get_height() {
    return cards.empty() ? 0 : cards.at(0).size();
}