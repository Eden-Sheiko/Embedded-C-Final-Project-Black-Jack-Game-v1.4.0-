//
// Created by edens on 27/09/2022.
//


#include "Card.h"



uint8_t Card_get_rank(card_t* card) {
    return ((card -> data) & (15 /*binary 1111*/ << 2)) >> 2;
}

uint8_t Card_get_suit(card_t* card) {
    return (card -> data) & 3 /*binary 11*/;
}

void Card_set_rank(card_t* card, uint8_t rank) {
    (card -> data) = (card -> data) | (rank << 2);
}


void Card_set_suit(card_t* card, uint8_t suit) {
    (card -> data) = (card -> data) | suit;
}


