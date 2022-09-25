//
// Created by Eden on 23/09/2022.
//

#ifndef WSL_CARDLIST_H
#define WSL_CARDLIST_H

#include "Card.h"



typedef struct cardlist{
    card_t *head;
    size_t len; // cache
}cardlist_t;


void init_card_deck(cardlist_t* deck);

card_t *get_random_card_from_deck(cardlist_t* deck);

void delete_data_node(card_t*);

void push_card_to_list(cardlist_t*,card_t *);

void print_player_deck(cardlist_t *);

void print_dealer_deck(cardlist_t *);

void print_dealer_deck_half(cardlist_t *);

void free_init(cardlist_t *);

void print_list(cardlist_t *);

bool is_black_jack_player(cardlist_t *);

bool is_bust(cardlist_t *);

int return_sum(cardlist_t *);

void print_status_print(int, int);

void print_new_game();

void print_game_over();

void print_game_name();

void print_bust();

void print_you_lose();

void print_dealer_bust();

void print_draw();

void print_dealer_wins();

void print_player_wins();

void betting(unsigned int,unsigned int*,int,int*);


void Lost_bet(unsigned int,unsigned int);


#endif //WSL_CARDLIST_H
