//main.c
#include <stdio.h>
#include <stdbool.h>
#include "player.h"
#include "monster.h"
#include "dice.h"
#include "events.h"

int main() {

	init_dice();

	Player p1 = create_player();
	GameState game_state = STATE_TUTORIAL;

	ui_display_intro_message();

	while (current_state != STATE_GAME_OVER) {

		switch (current_state) {

			case STATE_TUTORIAL:
				// pass player pointer so combat can modify player
				run_tutorial(&p1);
				current_state = STATE_REST;
				break;
			case STATE_REST:
				run_rest_menu(&p1);

				//when choose to end rest move to random event
				current_state = STATE_RANDOM_EVENT;
				break;
			case STATE_RANDOM_EVENT:
				run_random_event(&p1);

				if (p1.health <= 0) {
					current_state = STATE_GAME_OVER;
				} else {
					current_state = STATE_REST;
				}
		}
	}

	printf("\nYour journey has come to an end.\n");
	combat_event(&p1);

	return 0;
}
