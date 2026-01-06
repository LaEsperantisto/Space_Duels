#pragma once

#include <vector>

#include "Card.h"


typedef std::vector<std::vector<Card>> CardVec2D;
typedef std::initializer_list<std::initializer_list<Card>> CardInitList2D;


class Ship {
private:
    CardVec2D cards;
    int num_hubs = 0;
    bool isLegal = true;
    int alignment_index = -1;

    static bool isHub(const Card& card);
    void init_hub_count();

public:
    Ship(CardVec2D cards);
    Ship(CardInitList2D cards);
    CardVec2D getCards();
    int get_alignment_index();

    int get_width();
    int get_height();
};