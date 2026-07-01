//player.h
#ifndef PLAYER_H
#define PLAYER_H

typedef struct {
	char name[20];
	int health;
	int maxHealth;
	int maxDamage;
} Player;

Player create_player();

#endif