#ifndef UI_H
#define UI_H
#include "player.h"
#include "monster.h"

void ui_clear_screen();
void ui_draw_combat_screen(Player *p, Monster *m);
void ui_draw_monster_art(Monster *m);
void ui_display_intro_message();

#endif