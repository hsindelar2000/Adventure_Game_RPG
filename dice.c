//dice.c
#include <stdlib.h>
#include <time.h>
#include "dice.h"

void init_dice() {
    srand((unsigned int)time(NULL));
}

int roll(int sides) {
    if (sides <= 0) {
        return 0; // Return 0 for invalid sides
    }
    return (rand() % sides) + 1;
}