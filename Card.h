//
// Created by Eden on 23/09/2022.
//

#ifndef WSL_CARD_H
#define WSL_CARD_H

#include <stdint.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define  SUITS 4

#define  RANKS 13

typedef struct card{
    uint8_t data;
    struct card* next;
}card_t;

uint8_t Card_get_rank(card_t* card);

uint8_t Card_get_suit(card_t* card);

void Card_set_rank(card_t* card, uint8_t rank);

void Card_set_suit(card_t* card, uint8_t suit);


#endif //WSL_CARD_H
