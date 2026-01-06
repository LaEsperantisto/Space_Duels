#include "bots.h"

Ship bot0 = {
    {Hub(1)},
};

Ship bot1 = {
    {Thruster(1), Hub(1), Turret(1, 1)},
};

Ship bot2 = {
    {Thruster(1), Empty(), Empty()},
    {Thruster(2), Hub(1), Turret(1, 3)},
    {Thruster(1), Empty(), Empty()},
};

Ship bot3 = {
    {Thruster(2), Empty(), Empty()},
    {Thruster(2), Hub(2), Turret(2, 3)},
    {Thruster(2), Empty(), Empty()},
};