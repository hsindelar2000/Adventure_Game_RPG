//events.h
#ifndef EVENTS_H
#define EVENTS_H
#include "player.h"

void combat_event(Player *p);
void run_tutorial(Player *p);
void run_rest_menu(Player *p);
void run_random_event(Player *p);

#endif