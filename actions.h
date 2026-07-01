//actions.h
#ifndef ACTIONS_H
#define ACTIONS_H
#include <stdbool.h>
#include "player.h"
#include "monster.h"

void attack(Player *p, Monster *m, bool isPlayerTurn);

#endif