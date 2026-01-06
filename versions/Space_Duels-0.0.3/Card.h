#pragma once

#include <string>
// #include <unordered_map>
#include <array>

class Card {
protected:
    int rank = -1;

public:
    virtual ~Card() = default;

    [[nodiscard]] virtual int get_power() const { return 0; };
    [[nodiscard]] virtual int get_rank() const { return rank; }

    [[nodiscard]] virtual std::string get_short_name() const = 0;

    [[nodiscard]] virtual std::string get_name() const = 0;

    [[nodiscard]] virtual bool isEmpty() const { return false; }
    [[nodiscard]] virtual int get_weight() const { return 0; }
};


class Hub : public Card {
private:
    static constexpr std::array<int, 3> rank_to_power = {
        1,
        2,
        4,
    };

public:
    explicit Hub(int rank);

    [[nodiscard]] int get_power() const override;

    [[nodiscard]] int get_weight() const override;

    [[nodiscard]] std::string get_short_name() const override;

    [[nodiscard]] std::string get_name() const override;
};

class Empty final : public Card {
private:
public:
    Empty();

    [[nodiscard]] std::string get_name() const override;

    [[nodiscard]] std::string get_short_name() const override;

    [[nodiscard]] bool isEmpty() const override;
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
    explicit Turret(int rank, int level);

    [[nodiscard]] int get_power() const override;

    [[nodiscard]] int get_weight() const override;

    [[nodiscard]] std::string get_short_name() const override;

    [[nodiscard]] std::string get_name() const override;
};

class Thruster : public Card {
private:
    static constexpr std::array<int, 3> rank_to_power = {
        0,
        1,
        2,
    };

public:
    explicit Thruster(int rank);

    [[nodiscard]] int get_power() const override;

    [[nodiscard]] int get_weight() const override;

    [[nodiscard]] std::string get_short_name() const override;

    [[nodiscard]] std::string get_name() const override;
};
