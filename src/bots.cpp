#include "bots.h"
#include <memory>
#include <vector>

void setup_bots() {
}

const Ship bot0 =
    CardVec2D{
        { std::make_shared<Hub>(1) }
    };

const Ship bot1 =
    CardVec2D{
        {
            std::make_shared<Thruster>(1),
            std::make_shared<Hub>(1),
            std::make_shared<Turret>(1, 1)
        }
    };

const Ship bot2 =
    CardVec2D{
        {
            std::make_shared<Thruster>(1),
            std::make_shared<Empty>(),
            std::make_shared<Empty>()
        },
        {
            std::make_shared<Thruster>(2),
            std::make_shared<Hub>(1),
            std::make_shared<Turret>(1, 3)
        },
        {
            std::make_shared<Thruster>(1),
            std::make_shared<Empty>(),
            std::make_shared<Empty>()
        }
    };

const Ship bot3 =
    CardVec2D{
        {
            std::make_shared<Thruster>(2),
            std::make_shared<Empty>(),
            std::make_shared<Empty>()
        },
        {
            std::make_shared<Thruster>(2),
            std::make_shared<Hub>(2),
            std::make_shared<Turret>(2, 3)
        },
        {
            std::make_shared<Thruster>(2),
            std::make_shared<Empty>(),
            std::make_shared<Empty>()
        }
    };
