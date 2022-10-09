//
// Created by edens on 27/09/2022.
//

#ifndef WSL_BLACK_JACK_C99_CARD_H
#define WSL_BLACK_JACK_C99_CARD_H


#include <stdint.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/// Suits defines the amount of suits in a single card deck of 52 cards
#define  SUITS 4
/// Ranks defines the amount of Ranks in a single card deck of 52 cards
#define  RANKS 13
/// card is an linked list data structure which holds each data of the card and points
/// to the next one
///@param [uint8_t]  data which contains data of each card
///@param [struct card*] next pointer to the next node
typedef struct card{
    uint8_t data;
    struct card* next;
}card_t;

/// Card_get_rank gets the rank of the card
/// \param [card_t*] card the method receives pointer to card_t
/// \return [uint8_t] returns the rank of the card
uint8_t Card_get_rank(card_t* card);


/// Card_get_suit gets the suit of the card
/// \param [card_t*] card the method receives pointer to card_t
/// \return [uint8_t] returns the suit of the card
uint8_t Card_get_suit(card_t* card);

/// Card_set_rank set the rank of the card
/// \param [card_t*] card the param receives pointer to card_t
/// \param [uint8_t] rank the param receives the data of the card
/// \return [void] nothing
void Card_set_rank(card_t* card, uint8_t rank);


/// Card_set_suit set the suit of the card
/// \param [card_t*] card the param receives pointer to card_t
/// \param [uint8_t] rank the param receives the data of the card
/// \return [void] nothing
void Card_set_suit(card_t* card, uint8_t suit);



#endif //WSL_BLACK_JACK_C99_CARD_H
