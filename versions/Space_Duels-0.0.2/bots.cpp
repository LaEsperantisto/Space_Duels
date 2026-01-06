#include "bots.h"

Ship bot0 = {
    {new Hub(1)},
};

Ship bot1 = {
    {new Thruster(1), new Hub(1), new Turret(1, 1)},
};

Ship bot2 = {
    {new Thruster(1), new Empty(), new Empty()},
    {new Thruster(2), new Hub(1), new Turret(1, 3)},
    {new Thruster(1), new Empty(), new Empty()},
};

Ship bot3 = {
    {new Thruster(2), new Empty(), new Empty()},
    {new Thruster(2), new Hub(2), new Turret(2, 3)},
    {new Thruster(2), new Empty(), new Empty()},
};