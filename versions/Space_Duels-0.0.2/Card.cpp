#include "Card.h"

#include <iostream>

// Hub ------------------------------------------------------------------------

Hub::Hub(int rank) {
    this->rank = rank;
    this->name = "Hub";
    this->short_name = "Hub";
}

int Hub::get_power() const{
    if (this->rank > 0 && this->rank <= rank_to_power.size() - 1) {
        return rank_to_power.at(rank-1);
    }
    else {
        std::cerr << "Rank should only be 1 - 3";
        return 0;
    }
}

// Empty ------------------------------------------------------------------------


Empty::Empty() {
    this->name = "N/A";
    this->short_name = "   ";
    this->rank = 0;
}

// Turret -----------------------------------------------------------------------

Turret::Turret(int rank, int level) {
    this->name = "Turret";
    this->short_name = "Tur";
    this->level = level;
    this->rank = rank;
}

int Turret::get_power() const{
    if (this->rank > 0 && this->rank <= rank_to_power.size() - 1) {
        return rank_to_power.at(rank - 1) + this->level;
    }
    else {
        std::cerr << "Rank should only be 1 - 3";
        return 0;
    }
}

// Thruster -----------------------------------------------------------------------

Thruster::Thruster(int rank) {
    this->short_name = "Thr";
    this->name = "Thruster";
    this->rank = rank;
}

int Thruster::get_power() const{
    if (this->rank > 0 && this->rank <= rank_to_power.size() - 1) {
        return rank_to_power.at(rank-1);
    }
    else {
        std::cerr << "Rank should only be 1 - 3";
        return 0;
    }
}