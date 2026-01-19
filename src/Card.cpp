#include "Card.h"

#include <iostream>
#include <utility>

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

std::shared_ptr<Card> Card::get_flipped_card() const {
    return std::make_shared<Empty>();
}

// Hub ------------------------------------------------------------------------

Hub::Hub(const int rank) {
    this->rank = rank;
}

int Hub::get_power() const {
    if (this->rank > 0 && this->rank <= static_cast<int>(rank_to_power.size())) {
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
    if (this->rank > 0 && this->rank <= static_cast<int>(rank_to_power.size())) {
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
    if (this->rank > 0 && this->rank <= static_cast<int>(rank_to_power.size())) {
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

// Wall ------------------------------------------------------------------------

Wall::Wall(const int rank) {
    this->rank = rank;
}

int Wall::get_power() const {
    if (this->rank > 0 && this->rank <= static_cast<int>(rank_to_power.size())) {
        return rank_to_power.at(rank - 1);
    }
    std::cerr << "Rank should only be 1 - 3";
    return 0;
}

int Wall::get_weight() const {
    return 2;
}

std::string Wall::get_name() const {
    return "Wall";
}

std::string Wall::get_short_name() const {
    return "Wal";
}

QString Wall::get_description() const {
    return {
        "The Wall is the most basic type of defense. Rank 1 is stable, Rank 2 is resistant and super stable,"
        "and Rank 3 is super resistant and ultra stable."
    };
}

// Relay ------------------------------------------------------------------------

Relay::Relay(const int rank) {
    this->rank = rank;
}

int Relay::get_power() const {
    if (this->rank > 0 && this->rank <= static_cast<int>(rank_to_power.size())) {
        return rank_to_power.at(rank - 1);
    }
    std::cerr << "Rank should only be 1 - 3";
    return 0;
}

int Relay::get_weight() const {
    return 1;
}

std::string Relay::get_name() const {
    return "Relay";
}

std::string Relay::get_short_name() const {
    return "Rel";
}

QString Relay::get_description() const {
    return {
        "The Relay, aka the Power Relay, is similar to the wall, but is designed for relaying power between cards."
        "A Rank 1 Relay is stable, Rank 2 is super stable, Rank 3 is super stable and has a power of 1."
    };
}

// Round_swallower ------------------------------------------------------------------------

Round_swallower::Round_swallower(const int rank) {
    this->rank = rank;
}

int Round_swallower::get_power() const {
    return 0;
}

int Round_swallower::get_weight() const {
    return 2;
}

std::string Round_swallower::get_name() const {
    return "Round-swallower";
}

std::string Round_swallower::get_short_name() const {
    return "Rsw";
}

QString Round_swallower::get_description() const {
    return {
        "The Round-swallower is the first unlockable Energy-generator. The round after it is destroyed or demolished,"
        "it produces the same Energy as the type of Round that destroyed or demolished it (e.g. gets hit by Explosive"
        "Rounds, produces Explosive Round Energy). It can only produce energy when it \"becomes\" not intact; takes"
        "the initial hit."
    };
}

// Flipped ------------------------------------------------------------------------

Flipped::Flipped(std::shared_ptr<Card> &card) : flipped_card(std::move(card)) {
}

int Flipped::get_power() const {
    return 0;
}

int Flipped::get_weight() const {
    return 1;
}

std::string Flipped::get_name() const {
    return "Flipped-" + flipped_card->get_name();
}

QString Flipped::get_description() const {
    return {"A Flipped card that has no Rank and no power, but can sometimes be restored."};
}

std::string Flipped::get_short_name() const {
    return "Flp";
}

std::shared_ptr<Card> Flipped::get_flipped_card() const {
    return flipped_card;
}

QPixmap Flipped::get_texture() const {
    if (QPixmap pixmap(QString(":/gfx/Flipped-%1.png")
            .arg(QString::fromStdString(flipped_card->get_name())));
        !pixmap.isNull()) {
        return pixmap;
    }
    return {":gfx/texture_error.png"};
}

inline bool Flipped::isFlipped() const {
    return true;
}
