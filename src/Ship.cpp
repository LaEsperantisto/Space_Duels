#include "Ship.h"

#include <memory>
#include <set>

Ship::Ship(CardVec2D cards) : cards(std::move(cards)) {
    update_data();
}

Ship::Ship() = default;

const CardVec2D &Ship::get_cards() const {
    return cards;
}

bool Ship::isHub(const Card &card) {
    if (card.get_short_name() == "Hub") return true;
    if (card.get_short_name() == "Flp") {
        return card.get_flipped_card()->get_short_name() == "Hub";
    }
    return false;
}

void Ship::check_cards() {
    num_hubs = 0;
    alignment_index = -1;
    isLegal = true;

    for (unsigned int x = 0; x < get_width(); ++x) {
        for (unsigned int y = 0; y < get_height(); ++y) {
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
    return static_cast<int>(alignment_index);
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
    if (weight > 0) isLegal = false;
}

// void Ship::set_cards(CardVec2D &new_cards) {
//     cards = std::move(new_cards);
//     update_data();
// }

bool Ship::is_legal() const {
    return isLegal;
}

void Ship::add_column_back() {
    std::vector<CardPtr> col(get_height());

    for (unsigned int i = 0; i < get_height(); ++i)
        col.push_back(std::make_shared<Empty>());

    cards.push_back(std::move(col));
    update_data();
}

void Ship::add_column_front() {
    std::vector<CardPtr> col(get_height());

    for (unsigned int i = 0; i < get_height(); ++i)
        col.push_back(std::make_shared<Empty>());

    cards.insert(cards.begin(), std::move(col));
    update_data();
}

void Ship::change_card(const int x, const int y, const CardPtr &card) {
    cards.at(x).at(y) = card;
}

void Ship::add_row_bottom() {
    for (auto &row: cards) {
        row.push_back(std::make_shared<Empty>());
    }
}

void Ship::add_row_top() {
    for (auto &row: cards) {
        row.insert(row.begin(), std::make_shared<Empty>());
    }
}

void Ship::remove_column_back() {
    cards.pop_back();
}

void Ship::remove_column_front() {
    cards.erase(cards.begin());
}

void Ship::remove_row_bottom() {
    for (auto &row: cards) {
        row.pop_back();
    }
}

void Ship::remove_row_top() {
    for (auto &row: cards) {
        row.erase(row.begin());
    }
}

int Ship::get_col_power(const int x) const {
    int output = 0;
    for (const auto &card: cards.at(x)) {
        output += card->get_power();
    }
    return output;
}

std::set<Round *> Ship::get_col_rounds(const int x) const {
    std::set<Round *> output;
    for (const auto &card: cards.at(x)) {
        for (auto round: card->get_rounds()) {
            output.insert(round);
        }
    }
    return output;
}
