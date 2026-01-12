#include "Card.h"

#include <iostream>

// Card ------------------------------------------------------------------------

QPixmap Card::get_texture() const {
    if (QPixmap pixmap(QString(":/gfx/%1_%2.png")
            .arg(QString::fromStdString(get_name()))
            .arg(get_rank()));
        !pixmap.isNull()) {
        return pixmap;
    }
    return {":gfx/texture_error.png"};
}

QString Card::get_details() const {
    return QString("Card: %1 power: %2 rank: %3")
            .arg(QString::fromStdString(get_name()))
            .arg(get_power())
            .arg(get_rank());
}

// Hub ------------------------------------------------------------------------

Hub::Hub(const int rank) {
    this->rank = rank;
}

int Hub::get_power() const {
    if (this->rank > 0 && this->rank <= rank_to_power.size()) {
        return rank_to_power.at(rank - 1);
    }
    std::cerr << "Rank should only be 1 - 3";
    return 0;
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

QString Hub::get_description() const {
    return {
        "The Hub is your life. Lose your Hub, lose the game. A Rank 1 Hub is destroyed by any round,"
        "a Rank 2 Hub is resistant, and a Rank 3 Hub is super resistant. Note: having a Debris of Hub"
        "still counts as a Hub."
    };
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
    if (this->rank > 0 && this->rank <= rank_to_power.size()) {
        return rank_to_power.at(rank - 1) + this->level;
    }
    std::cerr << "Rank should only be 1 - 3";
    return 0;
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

QString Turret::get_details() const {
    return QString("Card: Turret power: %1 rank: %2 level: %3")
            .arg(get_power())
            .arg(get_rank())
            .arg(get_level());
}

QString Turret::get_description() const {
    return {
        "The turret is the most basic weapon, capable of firing only ballistic rounds."
        "The turret is also the first unlockable weapon, aside from the Hub."
    };
}

int Turret::get_level() const {
    return level;
}

// Thruster -----------------------------------------------------------------------

Thruster::Thruster(const int rank) {
    this->rank = rank;
}

int Thruster::get_power() const {
    if (this->rank > 0 && this->rank <= rank_to_power.size()) {
        return rank_to_power.at(rank - 1);
    }
    std::cerr << "Rank should only be 1 - 3";
    return 0;
}

int Thruster::get_weight() const {
    return rank_to_weight.at(rank - 1);
}

std::string Thruster::get_name() const {
    return "Thruster";
}

std::string Thruster::get_short_name() const {
    return "Thr";
}

QString Thruster::get_description() const {
    return {
        "Thrusters are very important. If you don't have enough thrusters, you can't shoot your opponent."
        "A Rank 1 Thruster supports 3 other cards."
    };
}
