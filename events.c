//events.c
#include <stdio.h>
#include <stdbool.h>
#include "player.h"
#include "monster.h"
#include "actions.h"
#include "ui.h"


void combat_event(Player *p, Monster *m) {

	printf("A %s blocks your path.\n", m->name);

	bool in_combat = true;
	bool player_turn = true;
	int choice;

	while (in_combat && m->health > 0) {
		ui_draw_combat_screen(p, m);
			
		scanf("%d", &choice);

		if (choice == 1) {
			attack(p, m, player_turn);
			player_turn = !player_turn; // Switch turns
		}
		else if (choice == 2) {
			printf("\nYou bravely flee from the %s.\n", m->name);
			in_combat = false;
			player_turn = true; // Reset turn for next combat
		}
		else if (choice == 3) {
			printf("\nYou give up and accept your fate.\n");
			p->health = 0; // Player gives up, set health to 0
			in_combat = false;
		}
		else {
			printf("\nInvalid choice, your hesitation costs you a turn.\n");
		}
	}

	printf("\nCombat has ended.\n");
}

void run_tutorial(Player *p) {
	//spawns a goblin for the tutorial combat
	Monster m = spawn_tutorial_monster();
	combat_event(p, &m);
}

void run_rest_menu(Player *p) {
	int choice;
	printf("\nYou find a safe place to rest.\n");
	printf("1. Rest and recover health\n");
	printf("2. Continue your journey\n");
	printf("3. Give up\n");
	scanf("%d", &choice);

	if (choice == 1) {
		p->health = p->maxHealth;
		printf("\nYou have fully recovered your health!\n");
	} else if (choice == 2) {
		printf("\nYou continue your journey.\n");
	} else if (choice == 3) {
		printf("\nYou give up on your journey.\n");
	}
}

void run_random_event(Player *p) {
	// For now, just spawn a random monster for combat
	Monster m = spawn_random_monster();
	combat_event(p, &m);
}

