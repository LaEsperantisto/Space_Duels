#include "Round.h"

#include "Ship.h"


Round::Round(const std::function<void(int, int, Ship &, int)> &hit) : hit(hit) {
}


void Ballistic_func(const int x, const int y, Ship &ship, const int power) {
	CardPtr card = ship.get_cards().at(x).at(y);

	if (card->isEmpty() && x > 0) {
		Ballistic_func(x, y, ship, power);
	} else {
		if (card->isFlipped()) {
			ship.change_card(x, y, std::make_unique<Empty>());
		}
			if (power >= card->get_power()) {
				ship.change_card(x, y, std::make_unique<Flipped>(card));
			}
	}
}

Round Ballistic{
	Ballistic_func
};
