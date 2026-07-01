//actions.c
#include <stdio.h>
#include <stdbool.h>
#include "player.h"
#include "monster.h"
#include "dice.h"

void attack(Player *p, Monster *m, bool isPlayerTurn) {
    // 1. Roll damage based on whose turn it is
    int damage = roll(isPlayerTurn ? p->maxDamage : m->maxDamage);
    
    // 2. Set a pointer to the health variable of whoever is being attacked
    int *targetHealth = isPlayerTurn ? &m->health : &p->health;

    // 3. Check for a miss FIRST (before altering the damage variable)
    if (damage == 1) {
        if (isPlayerTurn) {
            printf("\nYour attack misses the %s.\n", m->name);
        } else {
            printf("\nThe %s's attack misses you.\n", m->name);
        }
        return; // Exit the function early since no damage is dealt
    }

    // 4. Prevent overkill
    if (damage > *targetHealth) {
        damage = *targetHealth; 
    }

    // 5. Apply the damage using our pointer
    *targetHealth -= damage;

    // 6. Print the results
    if (isPlayerTurn) {
        printf("\nYou attack the %s for %d damage!\n", m->name, damage);
        printf("The %s has %d health remaining.\n", m->name, *targetHealth);
    } else {
        printf("\nThe %s attacks you for %d damage!\n", m->name, damage);
        printf("You have %d health remaining.\n", *targetHealth);
    }   
}