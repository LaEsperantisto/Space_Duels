#include "Ship.h"

#include <memory>

Ship::Ship(CardVec2D cards) : cards(std::move(cards)) {
    update_data();
}

Ship::Ship() = default;


// Ship::Ship(CardInitList2D &init) {
//     cards.reserve(init.size());
//
//     for (auto &column: init) {
//         std::vector<CardPtr> col;
//         col.reserve(column.size());
//
//         for (auto &card: column) {
//             // copy unique_ptr by cloning the raw pointer
//             col.push_back(card);
//         }
//
//         cards.push_back(std::move(col));
//     }
//
//     update_data();
// }


const CardVec2D &Ship::get_cards() const {
    return cards;
}

bool Ship::isHub(const Card &card) {
    return card.get_short_name() == "Hub";
}

void Ship::check_cards() {
    num_hubs = 0;
    alignment_index = -1;
    isLegal = true;

    for (int x = 0; x < get_width(); ++x) {
        for (int y = 0; y < get_height(); ++y) {
            if (!isHub(*cards[x][y])) continue;

            num_hubs++;
            alignment_index = x;

            if (num_hubs > 1) {
                isLegal = false;
                return;
            }
        }
    }

    if (num_hubs != 1) {
        isLegal = false;
    }
}

// bool Ship::is_legal() const {
//     update_data();
//
//     return isLegal;
// }

int Ship::get_alignment_index() const {
    return alignment_index;
}

unsigned int Ship::get_width() const {
    return cards.size();
}

unsigned int Ship::get_height() const {
    return cards.empty() ? 0 : cards.at(0).size();
}

void Ship::update_data() {
    isLegal = true;
    check_cards();
    update_weight_count();
}

void Ship::update_weight_count() {
    weight = 0;
    for (const auto &row: cards) {
        for (const auto &card: row) {
            weight += card->get_weight();
        }
    }
    if (weight < 0) isLegal = false;
}

// void Ship::set_cards(CardVec2D &new_cards) {
//     cards = std::move(new_cards);
//     update_data();
// }

bool Ship::is_legal() const {
    return isLegal;
}

void Ship::add_column_back() {
    std::vector<CardPtr> col;
    col.reserve(get_height());

    for (int i = 0; i < get_height(); ++i)
        col.push_back(std::make_unique<Empty>());

    cards.push_back(std::move(col));
}

void Ship::add_column_front() {
    std::vector<CardPtr> col;
    col.reserve(get_height());

    for (int i = 0; i < get_height(); ++i)
        col.push_back(std::make_unique<Empty>());

    cards.insert(cards.begin(), std::move(col));
}
