#pragma once

#include <vector>
#include <memory>

#include "Card.h"

using CardPtr = std::unique_ptr<Card>;
using CardVec2D = std::vector<std::vector<CardPtr> >;
using CardInitList2D = std::initializer_list<std::initializer_list<CardPtr> >;


class Ship {
private:
    CardVec2D cards;
    int num_hubs = 0;
    bool isLegal = true;
    int alignment_index = -1;
    int weight = 0;

    [[nodiscard]]
    static bool isHub(const Card &card);

    void check_cards();

    void update_weight_count();

public:
    // explicit Ship(CardVec2D &cards);

    // Ship(CardInitList2D cards);
    Ship();

    [[nodiscard]]
    const CardVec2D &get_cards() const;


    void set_cards(CardVec2D &cards);

    [[nodiscard]]
    int get_alignment_index() const;

    [[nodiscard]]
    unsigned int get_width() const;

    [[nodiscard]]
    unsigned int get_height() const;

    [[nodiscard]]
    bool is_legal() const;

    void update_data();
};
