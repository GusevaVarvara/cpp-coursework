#include "Dice.h"

Dice::Dice() : seeded(false) {}

int Dice::roll() const {
    if (!seeded) {
        srand(static_cast<unsigned>(time(nullptr)));
        seeded = true;
    }

    return (rand() % 10) + 1;
}



