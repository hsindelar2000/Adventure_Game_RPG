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

	combat_event(&p1);

	return 0;
}
