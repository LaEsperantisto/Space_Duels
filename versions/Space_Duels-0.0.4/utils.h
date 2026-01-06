#pragma once
#include <utility>

class Ship;

void print_ships(const Ship &ship1, const Ship &ship2);

std::pair<Ship, Ship> align_ships(Ship ship1, Ship ship2);
