#pragma once
#include <QPainter>
#include <utility>

class Ship;

void draw_ships(QPainter &painter,
                const Ship &ship1,
                const Ship &ship2,
                const QWidget *widget,
                const std::pair<int, int> &mouse_pos);

std::pair<Ship, Ship> align_ships(Ship ship1, Ship ship2);
