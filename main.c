#include "CardList.h"
#include "time.h"


void Reset_cards(cardlist_t *,cardlist_t *,cardlist_t *list);


int main(int argc,char** argv)
{
    print_game_name();
    srand(time(NULL));

    unsigned int amount=0;
    int cash=1000;
    int pot=0;

    unsigned int player_sum=0;
    unsigned int dealer_sum=0;

    int h_s=0;

    int player_choice=0;
    cardlist_t deck = {
            .head = NULL,
            .len = 0,
    };

    cardlist_t dealer_hand= {
            .head = NULL,
            .len = 0,
    };

    cardlist_t player_hand= {
            .head = NULL,
            .len = 0,
    };

    init_card_deck(&deck);
    //print_list(&deck);
    while (1) {

        print_new_game();
        betting(cash,&cash,pot,&pot);

        card_t *random_card_p_1=get_random_card_from_deck(&deck);
        card_t *random_card_p_2=get_random_card_from_deck(&deck);
        card_t *random_card_d_1=get_random_card_from_deck(&deck);
        card_t *random_card_d_2=get_random_card_from_deck(&deck);

        push_card_to_list(&player_hand,random_card_p_1);
        push_card_to_list(&player_hand,random_card_p_2);
        push_card_to_list(&dealer_hand,random_card_d_1);
        push_card_to_list(&dealer_hand,random_card_d_2);


        print_player_deck(&player_hand);
        print_dealer_deck_half(&dealer_hand);

            bool is_black_jack = is_black_jack_player(&player_hand);
            if(is_black_jack==1)
            {
                cash=cash+(pot*2.5);
                pot=0;
                //Reset_cards()
            }
            // hit or stand
            printf("Do you wanna hit(press 1) or stand press(press 0) \n?");
            scanf("%d",&h_s);
            fflush(stdin);
            fflush(stdout);
        if (h_s==0) {

        }
        else if(h_s==1) {

            while (1) {
                int tmp;
                printf("to draw card press everything-yes 0-no\n");
                scanf("%d",&tmp);
                if(tmp==0)
                {
                    break;
                }
                else
                {
                    card_t *random_card_p_3 = get_random_card_from_deck(&deck);
                    push_card_to_list(&player_hand, random_card_p_3);
                    bool bust = is_bust(&player_hand);
                    if (bust == 1) {
                        Lost_bet(cash, pot);
                        break;
                    }
                    print_player_deck(&player_hand);
                }

            }
        }
        print_player_deck(&player_hand);
        print_dealer_deck(&dealer_hand);

// dealer draw


        player_sum = return_sum(&player_hand);
        dealer_sum = return_sum(&dealer_hand);
        printf("before update \n");
        printf("player score- >%d\n",player_sum);
        printf("dealer score- >%d\n",dealer_sum);

        while(dealer_sum<17)
        {
            card_t *random_card_d_3 = get_random_card_from_deck(&deck);
            push_card_to_list(&dealer_hand, random_card_d_3);
            dealer_sum = return_sum(&dealer_hand);
        }
        printf("after update --------\n");
        printf("player score- >%d\n",player_sum);
        printf("dealer score- >%d\n",dealer_sum);


            if (dealer_sum > player_sum)
            {
                print_you_lose();
                pot=0;
            }
            else if (dealer_sum > 21)
            {
                print_dealer_bust();
                cash += (pot * 2);
                pot = 0;
                //rest cards
            }
            else if (dealer_sum <= 21 && dealer_sum == player_sum)
            {
                print_draw();
                //REST cards
            }
            else if (dealer_sum <= 21 && dealer_sum > player_sum)
            {
                print_dealer_wins();
                pot = 0;
                //rest cards
            }
            else if (dealer_sum <= 21 && dealer_sum < player_sum)
            {
                print_player_wins();
                //rest cards
                cash = cash + (pot * 2);
                pot = 0;
            }



            // rest cards;
            //Reset_cards(&deck,&dealer_hand,&player_hand);

            printf("would you like to continue? press 0 for yes or anything else for no\n");
            scanf("%d",&player_choice);
            while (getchar() != '\n');
            fflush(stdout);
            if (pot==0 && cash < 10)
            {
                print_game_over();
                free_init(&dealer_hand);
                free_init(&player_hand);
                break;

            }
            if(player_choice!=0)
            {
                free_init(&dealer_hand);
                free_init(&player_hand);
                print_game_over();
                break;
            }
            if (player_hand.len>0 && dealer_hand.len>0)
            {
                free_init(&dealer_hand);
                free_init(&player_hand);
            }
        }
    free_init(&deck);
    return 0;
    }


void print_status_print(int c, int p)
{
    printf("===========================================\n");
    printf("\t\t Cash:%d ,Pot:%d \n",c,p);
    printf("===========================================\n");
}

void betting(unsigned int cash,unsigned int *cash_return,int pot,int *pot_return)
{
    unsigned int money;
    print_status_print(cash,pot);
    printf("How much would you like to bet? \n");
    printf("Enter a number in multiples of 10: \n");
    fflush(stdout);
    if(pot==0 && cash <10)
    {
        print_game_over();
        return;
    }
    while(1)
    {
        scanf("%d",&money);
        while (getchar() != '\n');
        if (money % 10 == 0 && money <= cash)
        {
            cash -= money;
            pot += money;
            *pot_return=pot;
            *cash_return=cash;
            //todo: call to Initial Deal: func
            break;
        }
        else
        {
            printf("Error , please Enter a number in multiples of 10:\n");

        }
    }
}

void Lost_bet(unsigned int cash,unsigned int pot)
{
    pot=0;
    print_bust();
}


void Reset_cards(cardlist_t *deck,cardlist_t *dealer_hand,cardlist_t *player_hand)
{
    free_init(deck);
    init_card_deck(deck);
    free_init(dealer_hand);
    free_init(player_hand);
}