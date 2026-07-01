//monster.h
#ifndef MONSTER_H
#define MONSTER_H

typedef enum {
	MONSTER_GOBLIN,
	MONSTER_ORC,
	MONSTER_OGRE
} MonsterType;

typedef struct {
	MonsterType type;
	char name[20];
	int health;
	int maxDamage;
} Monster;

Monster spawn_random_monster();
Monster spawn_tutorial_monster();

#endif
