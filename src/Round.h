#pragma once
#include <functional>

class Ship;

class Round {
public:
	std::function<void(int, int, Ship &, int)> hit;

	Round(const std::function<void(int, int, Ship &, int)> &hit);
};

extern Round Ballistic;
