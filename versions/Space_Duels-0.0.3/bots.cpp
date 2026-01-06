#include "bots.h"
#include <memory>
#include <vector>

Ship bot0;
Ship bot1;
Ship bot2;
Ship bot3;

void setup_bots() {
}

/*const Ship bot0(
    std::vector<std::vector<std::unique_ptr<Card> > >{
        {
            std::make_unique<Hub>(1),
        }
    }
);

const Ship bot1(
    std::vector<std::vector<std::unique_ptr<Card> > >{
        {
            std::make_unique<Thruster>(1),
            std::make_unique<Hub>(1),
            std::make_unique<Turret>(1, 1)
        }
    }
);

const Ship bot2(
    std::vector<std::vector<std::unique_ptr<Card> > >{
        {
            std::make_unique<Thruster>(1),
            std::make_unique<Empty>(),
            std::make_unique<Empty>()
        },
        {
            std::make_unique<Thruster>(2),
            std::make_unique<Hub>(1),
            std::make_unique<Turret>(1, 3)
        },
        {
            std::make_unique<Thruster>(1),
            std::make_unique<Empty>(),
            std::make_unique<Empty>()
        }
    }
);

const Ship bot3(
    std::vector<std::vector<std::unique_ptr<Card> > >{
        {
            std::make_unique<Thruster>(2),
            std::make_unique<Empty>(),
            std::make_unique<Empty>()
        },
        {
            std::make_unique<Thruster>(2),
            std::make_unique<Hub>(2),
            std::make_unique<Turret>(2, 3)
        },
        {
            std::make_unique<Thruster>(2),
            std::make_unique<Empty>(),
            std::make_unique<Empty>()
        }
    }
);*/
