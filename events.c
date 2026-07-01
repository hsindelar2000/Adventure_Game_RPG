//events.c
#include <stdio.h>
#include <stdbool.h>
#include "player.h"
#include "monster.h"
#include "actions.h"

void combat_event(Player *p) {
	Monster m = spawn_random_monster();


	printf("A %s blocks your path.\n", m.name);

	bool in_combat = true;
	bool player_turn = true;
	int choice;

	while (in_combat && m.health > 0) {
		printf("What will you do?\n");
		printf("1. Attack\n");
		printf("2. Flee\n");
			
		scanf("%d", &choice);

		if (choice == 1) {
			attack(&p, &m, player_turn);
			player_turn = !player_turn; // Switch turns
		}
		else if (choice == 2) {
			printf("\nYou bravely flee from the %s.\n", m.name);
			in_combat = false;
			player_turn = true; // Reset turn for next combat
		}
		else {
			printf("\nInvalid choice, your hesitation costs you a turn.\n");
		}
	}

	printf("\nCombat has ended.\n");
}

