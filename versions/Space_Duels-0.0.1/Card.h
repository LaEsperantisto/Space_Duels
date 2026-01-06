#pragma once

#include <string>
#include <functional>
// #include <unordered_map>
#include <array>

class Card {
protected:
    int rank;
    std::string name;
    std::string short_name;
public:
    virtual int get_power() const { return 0; };
    int get_rank() const { return rank; }
    virtual ~Card() { };
    std::string get_name() const { return name; }
    std::string get_short_name() const { return short_name; }
    bool isEmpty() const { return name == "N/A"; }
};


class Hub : public Card {
private:
    static constexpr std::array<int, 3> rank_to_power = {
        1,
        2,
        4,
    };
public:
    Hub(int rank);
    int get_power();
};

class Empty : public Card {
private:
public:
    Empty();
};

class Turret : public Card {
private:
    int level;
    static constexpr std::array<int, 3> rank_to_power = {
        2,
        4,
        6,
    };
public:
    Turret(int rank, int level);
    int get_power();
};

class Thruster : public Card {
private:
    static constexpr std::array<int, 3> rank_to_power = {
        0,
        1,
        2,
    };
public:
    Thruster(int rank);
    int get_power();
};