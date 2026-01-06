#include "Card.h"

#include <iostream>

// Hub ------------------------------------------------------------------------

Hub::Hub(const int rank) {
    this->rank = rank;
}

int Hub::get_power() const {
    if (this->rank > 0 && this->rank <= rank_to_power.size() - 1) {
        return rank_to_power.at(rank - 1);
    } else {
        std::cerr << "Rank should only be 1 - 3";
        return 0;
    }
}

int Hub::get_weight() const {
    return 1;
}

std::string Hub::get_name() const {
    return "Hub";
}

std::string Hub::get_short_name() const {
    return "Hub";
}


// Empty ------------------------------------------------------------------------


Empty::Empty() {
    this->rank = 0;
}

std::string Empty::get_name() const {
    return "N/A";
}

std::string Empty::get_short_name() const {
    return "   ";
}

bool Empty::isEmpty() const {
    return true;
}

// Turret -----------------------------------------------------------------------

Turret::Turret(const int rank, const int level) {
    this->level = level;
    this->rank = rank;
}

int Turret::get_power() const {
    if (this->rank > 0 && this->rank <= rank_to_power.size() - 1) {
        return rank_to_power.at(rank - 1) + this->level;
    } else {
        std::cerr << "Rank should only be 1 - 3";
        return 0;
    }
}

int Turret::get_weight() const {
    return 1;
}

std::string Turret::get_name() const {
    return "Turret";
}

std::string Turret::get_short_name() const {
    return "Tur";
}

// Thruster -----------------------------------------------------------------------

Thruster::Thruster(const int rank) {
    this->rank = rank;
}

int Thruster::get_power() const {
    if (this->rank > 0 && this->rank <= rank_to_power.size() - 1) {
        return rank_to_power.at(rank - 1);
    } else {
        std::cerr << "Rank should only be 1 - 3";
        return 0;
    }
}

int Thruster::get_weight() const {
    return -3;
}

std::string Thruster::get_name() const {
    return "Thruster";
}

std::string Thruster::get_short_name() const {
    return "Thr";
}
