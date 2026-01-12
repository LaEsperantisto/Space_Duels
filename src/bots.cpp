#include "bots.h"
#include <memory>
#include <vector>

const std::array<Ship, 5> bots = {
    Ship{
        // bot 0
        CardVec2D{
            {
                std::make_shared<Thruster>(1),
                std::make_shared<Hub>(1)
            }
        }
    },
    Ship{
        // bot 1
        CardVec2D{
            {
                std::make_shared<Thruster>(1),
                std::make_shared<Hub>(1),
                std::make_shared<Turret>(1, 1)
            }
        }
    },
    Ship{
        // bot 2
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
        }
    },
    Ship{
        // bot 3
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
        },
    },
    Ship{
        // bot 4
        CardVec2D{
            {
                std::make_shared<Thruster>(2),
                std::make_shared<Turret>(1, 5),
                std::make_shared<Empty>(),
                std::make_shared<Empty>(),
            },
            {
                std::make_shared<Thruster>(3),
                std::make_shared<Hub>(2),
                std::make_shared<Turret>(2, 5),
                std::make_shared<Wall>(1),
            },
            {
                std::make_shared<Thruster>(2),
                std::make_shared<Turret>(1, 5),
                std::make_shared<Empty>(),
                std::make_shared<Empty>(),
            }
        }
    },
};
