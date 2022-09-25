//
// Created by Eden on 23/09/2022.
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

void print_new_game()
{
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("\t \t New Game \n");
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++\n");
}

void print_game_over()
{
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("\t \t Game Over!!! \n");
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++\n");
}

void print_game_name()
{
    printf("Embedded C Final Project Black-Jack Game (v1.4.0)\n");
    printf(" \t Created By : Eden Sheiko\n");
}

void print_bust()
{
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("\t \t BUST!!! \n");
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++\n");
}

void print_you_lose()
{
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("\t \t YOU LOSE!!! \n");
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++\n");
}

void print_dealer_bust()
{
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("\t \t Dealer Bust!!! \n");
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++\n");
}


void print_draw()
{
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("\t \t DRAW!!! \n");
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++\n");
}

void print_dealer_wins()
{
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("\t \t Dealer wins!!! \n");
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++\n");
}

void print_player_wins()
{
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("\t \t Player wins!!! \n");
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++\n");
}
