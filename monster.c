//monster.c
#include <stdlib.h>
#include <string.h>
#include "monster.h"
#include "dice.h"

Monster spawn_random_monster() {
	Monster m;

	switch (roll(3 - 1)) { // Roll a 3-sided die to determine monster type
    	case MONSTER_GOBLIN:
			m.type = MONSTER_GOBLIN;
			strcpy(m.name, "Goblin");
			m.health = 30;
			m.maxDamage = 5;
			break;
        
    	case MONSTER_ORC:
			m.type = MONSTER_ORC;
			strcpy(m.name, "Orc");
			m.health = 60;
			m.maxDamage = 12;
        	break;
        
    	case MONSTER_OGRE:
			m.type = MONSTER_OGRE;
			strcpy(m.name, "Ogre");
			m.health = 100;
			m.maxDamage = 25;
        	break;
	}

	return m;
}

Monster spawn_tutorial_monster() {
	Monster m;
	m.type = MONSTER_GOBLIN;
	strcpy(m.name, "Goblin");
	m.health = 30;
	m.maxDamage = 5;
	return m;
}


