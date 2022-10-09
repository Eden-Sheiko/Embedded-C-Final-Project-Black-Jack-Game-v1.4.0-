//
// Created by edens on 27/09/2022.
//

#include "CardList.h"
#include <stdlib.h>

const char *suits[SUITS] ={"Spades","Hearts","Clubs","Diamonds"};

const char *ranks[RANKS+1]={"None","Ace","2","3","4",
                            "5","6","7","8",
                            "9","10","Jack","Queen","King"};



void init_card_deck(cardlist_t *deck)
{
    card_t *last_node = NULL;
    card_t *new_node = NULL;
    for (uint8_t suit = 0; suit < SUITS; suit++) {
        for (uint8_t rank = 1; rank < RANKS + 1; rank++) {
            new_node = (card_t *) calloc(1, sizeof(*new_node));
            if (new_node == NULL) {
                perror("dynamic allocation error\n");
                return;
            }
            Card_set_rank(new_node, rank);
            Card_set_suit(new_node, suit);

            if (deck->head == NULL) {
                deck->head = new_node;
            } else {
                last_node->next = new_node;
            }
            deck->len++;
            last_node = new_node;
        }
    }
}

card_t *get_random_card_from_deck(cardlist_t* list) {
    int index = rand() % list -> len;
    card_t* tmp = NULL;
    if (index==0)
    {
        tmp = list -> head;
        list->head = list->head->next;
    } else {
        tmp = list->head;
        // arrive to item before requested
        while (index != 1) {
            tmp = tmp->next;
            index--;
        }
        card_t *result = tmp->next;
        tmp->next = result->next;
        tmp = result;
    }
    list -> len--;
    tmp -> next = NULL;
    return tmp;
}

void push_card_to_list(cardlist_t* list,card_t *data) {
    if (list->head==NULL) // case when its empty
    {
        list->head=data;
    } else {
        card_t *ptr = list->head;
        while (ptr->next != NULL) // case when not empty
        {
            ptr=ptr->next;
        }
        ptr->next=data;
    }
    data->next=NULL;
    list->len++;
}

void print_player_deck(cardlist_t *list)
{
    printf("Player hand:\n");
    card_t *ptr = list->head;
    while(ptr)
    {
        printf("     %s of %s\n", ranks[Card_get_rank(ptr)], suits[Card_get_suit(ptr)]);
        ptr=ptr->next;
    }
}

void print_dealer_deck(cardlist_t *list)
{
    printf("Dealer hand:\n");
    card_t *ptr = list->head;
    while(ptr)
    {
        printf("     %s of %s\n", ranks[Card_get_rank(ptr)], suits[Card_get_suit(ptr)]);
        ptr=ptr->next;
    }
}
void print_dealer_deck_half(cardlist_t *list)
{
    printf("Dealer hand:\n");
    card_t *ptr = list->head;
    while(1)
    {
        printf("     %s of %s\n", ranks[Card_get_rank(ptr)], suits[Card_get_suit(ptr)]);
        break;
    }
}

void free_init(cardlist_t *list)
{
    card_t *head = list -> head;
    while(head)
    {
        card_t *tmp = head;
        head=head->next;
        free(tmp);
    }
    list -> head = NULL;
    list->len=0;
}

bool is_black_jack_player(cardlist_t *list)
{
    int sum=0;
    card_t *ptr = list->head;

    while(ptr)
    {
        if(Card_get_rank(ptr)==11 ||Card_get_rank(ptr)==12||Card_get_rank(ptr)==13)
        {
            uint8_t tmp = 10;
            sum=sum+tmp;
            ptr=ptr->next;
            if(sum==21)
            {
                printf("+++++++++++++++++++++++++++++++++++++++++++++++++\n");
                printf("\t \t “Black Jack! \n");
                printf("+++++++++++++++++++++++++++++++++++++++++++++++++\n");
                return 1;
            }
        }
        else{
            if (Card_get_rank(ptr) == 1)
            {
                sum+=10;
                if(sum>21)
                {
                    sum-=10;
                }
            }
            sum=sum+Card_get_rank(ptr);
            ptr=ptr->next;
            if(sum==21)
            {
                printf("+++++++++++++++++++++++++++++++++++++++++++++++++\n");
                printf("\t \t “Black Jack! \n");
                printf("+++++++++++++++++++++++++++++++++++++++++++++++++\n");
                return 1;
            }
        }

    }
    return 0;
}

bool is_bust(cardlist_t *list)
{
    int sum=0;
    card_t *ptr = list->head;

    while(ptr)
    {
        if(Card_get_rank(ptr)==11 ||Card_get_rank(ptr)==12||Card_get_rank(ptr)==13)
        {
            uint8_t tmp = 10;

            sum=sum+tmp;
            ptr=ptr->next;
            if(sum>21)
            {
                return 1;
            }
        }
        else{
            if (Card_get_rank(ptr) == 1)
            {
                sum+=10;
                if(sum>21)
                {
                    sum-=10;
                }
            }
            sum=sum+Card_get_rank(ptr);
            ptr=ptr->next;
            if(sum>21)
            {

                return 1;
            }
        }

    }
    return 0;
}

int return_sum(cardlist_t *list)
{
    int sum=0;
    card_t *ptr = list->head;

    while(ptr)
    {
        if(Card_get_rank(ptr)==11 ||Card_get_rank(ptr)==12||Card_get_rank(ptr)==13)
        {
            uint8_t tmp = 10;

            sum=sum+tmp;
            ptr=ptr->next;

        }
        else{
            if (Card_get_rank(ptr) == 1)
            {
                sum+=10;
                if(sum>21)
                {
                    sum-=10;
                }
            }
            sum=sum+Card_get_rank(ptr);
            ptr=ptr->next;

        }

    }
    return sum;
}