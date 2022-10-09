//
// Created by edens on 27/09/2022.
//

#ifndef WSL_BLACK_JACK_C99_CARDLIST_H
#define WSL_BLACK_JACK_C99_CARDLIST_H


#include "Card.h"

/// cardlist is an linked list data structure which holds the head
/// of the card linked list and has cache of len
///@param [ card_t *]  head which contains the head of
/// the linked list
///@param [size_t] len length of linked list cache
typedef struct cardlist{
    card_t *head;
    size_t len;
}cardlist_t;

/// init_card_deck init the card deck
/// the function init linked list by using
/// card set suit and card set rank methods
/// \param [cardlist_t*] deck the method receives pointer to cardlist_t
/// \return [void] nothing
void init_card_deck(cardlist_t* deck);



/// get_random_card_from_deck
/// \param [cardlist_t*] deck the method receives pointer to cardlist_t
/// \return [card_t *] returns random card
card_t *get_random_card_from_deck(cardlist_t* deck);


/// push_card_to_list - pushes card data to linked list.
/// \param [cardlist_t*] deck the method receives pointer to cardlist_t
/// \param [card_t*] card  the method receives pointer to card_t
/// \return [void] nothing
void push_card_to_list(cardlist_t*,card_t *);

/// print_player_deck - prints player deck
/// \param [cardlist_t*] player_deck the method receives pointer to cardlist_t
/// \return [void] nothing
void print_player_deck(cardlist_t *);


/// print_dealer_deck - prints dealer deck
/// \param [cardlist_t*] dealer_deck the method receives pointer to cardlist_t
/// \return [void] nothing
void print_dealer_deck(cardlist_t *);


/// print_dealer_deck_half - prints dealer deck only half
/// \param [cardlist_t*] dealer_deck the method receives pointer to cardlist_t
/// \return [void] nothing
void print_dealer_deck_half(cardlist_t *);


/// free_init - free the init of the lists
/// \param [cardlist_t*] deck the method receives pointer to cardlist_t
/// \return [void] nothing
void free_init(cardlist_t *);


/// is_black_jack_player - checks if player has black_jack(21)
/// \param [cardlist_t*] deck the method receives pointer to cardlist_t
/// \return [bool] true or false
bool is_black_jack_player(cardlist_t *);


/// is_black_jack_player - checks if player has bust(above 21)
/// \param [cardlist_t*] deck the method receives pointer to cardlist_t
/// \return [bool] true or false
bool is_bust(cardlist_t *);

/// return_sum - return sum of cards
/// \param [cardlist_t*] deck the method receives pointer to cardlist_t
/// \return [int] sum
int return_sum(cardlist_t *);


/// print_status_print - print game cash and pot
/// \param [unsigned int] pot
/// \param [unsigned int] cash
/// \return [void] nothing
void print_status_print(unsigned int,unsigned int);


/// betting - betting phase - handling with cash and pot
/// \param [unsigned int] pot
/// \param [unsigned int*] pot_return
/// \param [unsigned int] cash
/// \param [unsigned int*] cash_return
/// \return [void] nothing
void betting(unsigned int,unsigned int*,unsigned int, unsigned int*);


#endif //WSL_BLACK_JACK_C99_CARDLIST_H
