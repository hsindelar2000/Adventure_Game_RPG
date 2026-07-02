//main.c
#include <stdio.h>
#include <stdbool.h>
#include "player.h"
#include "monster.h"
#include "dice.h"
#include "events.h"
#include "ui.h"

typedef enum {
	STATE_TUTORIAL,
	STATE_REST,
	STATE_RANDOM_EVENT,
	STATE_GAME_OVER
} GameState;

int main() {

	init_dice();

	Player p1 = create_player();
	GameState game_state = STATE_TUTORIAL;

	ui_display_intro_message();

	while (game_state != STATE_GAME_OVER) {

		switch (game_state) {

			case STATE_TUTORIAL:
				// pass player pointer so combat can modify player
				run_tutorial(&p1);
				game_state = STATE_REST;
				break;
			case STATE_REST:
				run_rest_menu(&p1);

				//check if player health is 0 after rest menu from giving up
				if (p1.health <= 0) {
					game_state = STATE_GAME_OVER;
					break;
				}

				//when choose to end rest move to random event
				game_state = STATE_RANDOM_EVENT;
				break;
			case STATE_RANDOM_EVENT:
				run_random_event(&p1);

				if (p1.health <= 0) {
					game_state = STATE_GAME_OVER;
					break;
				} else {
					game_state = STATE_REST;
				}
			break;
			case STATE_GAME_OVER:
				printf("\nYour journey has come to an end.\n");
				break;
		}
	}

	return 0;
}
