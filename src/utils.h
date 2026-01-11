#pragma once
#include <QPainter>
#include <utility>

class Ship;

void draw_ships(QPainter& painter,
				const Ship& ship1,
				const Ship& ship2,
				const QWidget* widget);

std::pair<Ship, Ship> align_ships(Ship ship1, Ship ship2);
