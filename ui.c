#include <stdio.h>
#include "ui.h"

void ui_clear_screen() {
    //clear screen and send cursor to top left corner
    printf("\033[2J\033[H");
}

void ui_draw_combat_screen(Player *p, Monster *m) {
    ui_clear_screen();

    //display enemy stats with ASCII art across top of screen
    printf("A wild %s appears!\n", m->name);

    //use function to insert ASCII art for monster
    ui_draw_monster_art(m);

    //render player stats and action menu
    printf("\nPlayer Stats:\n");
    printf("-----------------------------------------------\n");
    printf("  Player: %s [HP: %d/%d]\n", p->name, p->health, p->maxHealth);
    printf("-----------------------------------------------\n");
    printf("  1. Attack\n");
    printf("  2. Flee\n");
    printf("================================================\n");
    printf("Choose your action: ");
}

void ui_draw_monster_art(Monster *m) {
    switch (m->type) {
        case MONSTER_GOBLIN:
            printf("         ,      ,\n");
            printf("        /(.-\"\"-.)\\\n");
            printf("    |\\  \\/      \\/  /|\n");
            printf("    | \\ / =.  .= \\ / |\n");
            printf("    \\( \\   o\\/o   / )/\n");
            printf("     \\_, '-/  \\-' ,_/\n");
            printf("       /   \\__/   \\\n");
            printf("       \\ \\__/\\__/ /\n");
            printf("     ___\\ \\|--|/ /___\n");
            printf("    /`    \\      /    `\\\n");
            printf("   /       '----'       \\\n"); 
            break;
        case MONSTER_ORC:
            printf("                        _,.---''```````'-.\n");
            printf("                    ,-'`                  `-._\n");
            printf("                 ,-`                   __,-``,\\\n");
            printf("                /             _       /,'  ,|/ \\\n");
            printf("              ,'         ,''-<_`'.    |  ,' |   \\\n");
            printf("             /          / _    `  `.  | / \\ |\\  |\n");
            printf("             |         (  |`'-,---, `'  \\_|/ |  |\n");
            printf("             |         |`  \\  \\|  /  __,    _ \\ |\n");
            printf("             |         |    `._\\,'  '    ,-`_\\ \\|\n");
            printf("             |         |        ,----      /|   )\n");
            printf("             \\         \\       / --.      {/   /|\n");
            printf("              \\         | |       `.\\         / |\n");
            printf("               \\        / `-.                 | /\n");
            printf("                `.     |     `-        _,--V`)\\/        _,-\n");
            printf("                  `,   |           /``V_,.--`  \\.  _,-'`\n");
            printf("                   /`--'`._        `-'`         )`'\n");
            printf("                  /        `-.            _,.-'`\n");
            printf("                              `-.____,.-'`\n");
            break;
        case MONSTER_OGRE:
            printf("                           __,='`````'=/__\n");
            printf("                          '//  (o) \\(o) \\ `'         _,-,\n");
            printf("                          //|     ,_)   (`\\      ,-'`_,-\\\n");
            printf("                        ,-~~~\\  `'==='  /-,      \\==```` \\__\n");
            printf("                       /        `----'     `\\     \\       \\/\n");
            printf("                    ,-`                  ,   \\  ,.-\\       \\\n");
            printf("                   /      ,               \\,-`\\`_,-`\\_,..--'\\\n");
            printf("                  ,`    ,/,              ,>,   )     \\--`````\\\n");
            printf("                  (      `\\`---'`  `-,-'`_,<   \\      \\_,..--'`\n");
            printf("                   `.      `--. _,-'`_,-`  |    \\\n");
            printf("                    [`-.___   <`_,-'`------(    /\n");
            printf("                    (`` _,-\\   \\ --`````````|--`\n");
            printf("                     >-`_,-`\\,-` ,          |\n");
            printf("                   <`_,'     ,  /\\          /\n");
            printf("                    `  \\/\\,-/ `/  \\/`\\_/V\\_/\n");
            printf("                       (  ._. )    ( .__. )\n");
            printf("                       |      |    |      |\n");
            printf("                        \\,---_|    |_---./\n");
            printf("                        ooOO(_)    (_)OOoo\n"); 
            break;
        default:
            break;
    }
}

void ui_display_intro_message() {
    printf("Welcome to the Adventure Game!\n");
}