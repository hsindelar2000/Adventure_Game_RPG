//player.c
#include <stdlib.h>
#include <string.h>
#include "player.h"

Player create_player() {
	Player p;
	strcpy(p.name, "Hero");
	p.health = 100;
	p.maxHealth = 100;
	p.maxDamage = 10;
	return p;
}

//implement player init function that takes parameters for name, health, maxHealth, and maxDamage and eventually class


