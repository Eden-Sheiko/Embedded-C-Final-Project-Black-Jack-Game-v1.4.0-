#include "CardList.h"
#include "time.h"

void print_new_game();

void print_game_over();

void print_game_name();

void print_bust();

void print_dealer_bust();

void print_draw();

void print_dealer_wins();

void print_player_wins();

void game_menu();

void getting_card_player(cardlist_t* ,cardlist_t*);
void getting_card_dealer(cardlist_t* ,cardlist_t*);

void print_Initial_deal(cardlist_t*,cardlist_t*);

void is_black_jack_check(unsigned int,unsigned int*,unsigned int,unsigned int*,cardlist_t*,cardlist_t*);

void is_bust_check(unsigned int *);

void print_player_score(cardlist_t *);
void print_dealer_score(cardlist_t *);

void hit_or_stand(cardlist_t*,cardlist_t*,unsigned int *);

void Reset_cards(cardlist_t *dealer_hand, cardlist_t *player_hand);


int main(void)
{
    game_menu();
    fflush(stdin);
    fflush(stdout);
    srand(time(NULL));

    unsigned int cash = 1000;
    unsigned int pot = 0;

    unsigned int player_sum;
    unsigned int dealer_sum;

    int player_choice=0;

    cardlist_t deck = {0,0};
    cardlist_t dealer_hand = {0,0};
    cardlist_t player_hand = {0,0};


    init_card_deck(&deck);

    while (1) {

        print_new_game();
        betting(cash,&cash,pot,&pot);

        getting_card_player(&deck,&player_hand);
        getting_card_player(&deck,&player_hand);
        getting_card_dealer(&deck,&dealer_hand);
        getting_card_dealer(&deck,&dealer_hand);

        print_Initial_deal(&player_hand,&dealer_hand);
        print_player_score(&player_hand);

        bool is_black_jack = is_black_jack_player(&player_hand);
        if(is_black_jack == 1)
        {
            is_black_jack_check(cash,&cash,pot,&pot,&player_hand,&dealer_hand);
        }
        else
        {
            hit_or_stand(&deck,&player_hand,&pot);
            // if NO PRESSED
            print_player_deck(&player_hand);
            print_dealer_deck(&dealer_hand);

            player_sum = return_sum(&player_hand);
            dealer_sum = return_sum(&dealer_hand);
            fflush(stdout);
            fflush(stdin);

            print_player_score(&player_hand);

            while(dealer_sum<17)
            {
                getting_card_dealer(&deck,&dealer_hand);
                dealer_sum = return_sum(&dealer_hand);
            }
            print_dealer_deck(&dealer_hand);
            print_dealer_score(&dealer_hand);

            if(player_sum > 21)
            {
                print_dealer_wins();
                pot = 0;
                Reset_cards(&dealer_hand, &player_hand);
            }
            else if(dealer_sum>21)
            {
                print_player_wins();
                print_dealer_bust();
                Reset_cards(&dealer_hand, &player_hand);
                cash = cash + (pot * 2);
                pot = 0;
            }
            else if (dealer_sum <= 21 && dealer_sum == player_sum)
            {
                print_draw();
                Reset_cards(&dealer_hand, &player_hand);
            }
            else if (dealer_sum <= 21 && (dealer_sum > player_sum))
            {
                print_dealer_wins();
                pot = 0;
                Reset_cards(&dealer_hand, &player_hand);
            }
            else if (dealer_sum <= 21 && dealer_sum < player_sum)
            {
                print_player_wins();
                Reset_cards(&dealer_hand, &player_hand);
                cash = cash + (pot * 2);
                pot = 0;
            }
        }

        print_status_print(cash,pot);

        printf("would you like to continue? press 0 for yes or any number for no\n");
        scanf("%d",&player_choice);
        while (getchar() != '\n');
        fflush(stdout);
        if (pot == 0 && cash < 10)
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

void betting(unsigned int cash,unsigned int *cash_return,unsigned int pot,unsigned int *pot_return)
{
    unsigned int money;
    print_status_print(cash,pot);
    printf("How much would you like to bet? \n");
    printf("Enter a number in multiples of 10: \n");
    fflush(stdout);
    if(pot == 0 && cash <10)
    {
        print_game_over();
        return;
    }
    while(1)
    {
        scanf("%u",&money);
        while (getchar() != '\n');
        if (pot == 0 & money == 0)
        {
            printf("U must to bet on money \n");
        }
        else
        {
            if (money % 10 == 0 && money <= cash)
            {
                cash -= money;
                pot += money;
                *pot_return=pot;
                *cash_return=cash;
                break;
            }
            else if(money > cash)
            {
                printf("Error , please enter amount non bigger then your cash\n");
            }
            else if(money % 10 != 0)
            {
                printf("Error , please Enter a number in multiples of 10:\n");
            }
        }


    }
}


void Reset_cards(cardlist_t *dealer_hand, cardlist_t *player_hand)
{
    free_init(dealer_hand);
    free_init(player_hand);
}

void game_menu()
{
    char c;
    printf("\t\t\t***********************************\n");
    printf("\t\t\t** WELCOME TO BLACK JACK GAME **\n");
    printf("\t\t\t***********************************\n");
    printf("\t\t\t        Enter your choice: \n");
    printf("\t\t\t***********************************\n");
    printf("\t\t\t\t\tMENU\n\n\n");
    printf("\t\t\t\ta- Start game\n");
    printf("\t\t\t\tb- Game Creator\n");
    printf("\t\t\t\tc- Exit game\n");
    printf("\t\t\t***********************************\n\n\n");

    while(1) {
        scanf(" %c",&c);
        switch (c) {
            case 'a':
                return;
            case 'b':
                print_game_name();
                break;
            case 'c':
                exit(0);
            default:
                printf("Try again\n");
        }
    }

}

void getting_card_player(cardlist_t *deck ,cardlist_t *player_hand)
{
    card_t *random_card_p_1=get_random_card_from_deck(deck);

    push_card_to_list(player_hand,random_card_p_1);
}

void getting_card_dealer(cardlist_t *deck ,cardlist_t *dealer_hand)
{
    card_t *random_card_d_1 = get_random_card_from_deck(deck);

    push_card_to_list(dealer_hand, random_card_d_1);
}

void print_Initial_deal(cardlist_t *player_hand,cardlist_t *dealer_hand)
{
    print_player_deck(player_hand);
    print_dealer_deck_half(dealer_hand);
}

void is_black_jack_check(unsigned int cash,unsigned int *cash_return,unsigned int pot,unsigned int *pot_return,
                         cardlist_t *dealer_hand,cardlist_t *player_hand)
{
    cash=cash+(pot*2.5);
    pot = 0;
    *cash_return=cash;
    *pot_return=pot;
    Reset_cards(dealer_hand, player_hand);
}

void print_player_score(cardlist_t *player_hand)
{
    unsigned int player_score = return_sum(player_hand);
    printf("\n");
    printf("++++++++++++++++++++++++++++++\n");
    printf("player score -> %u\n",player_score);
    printf("++++++++++++++++++++++++++++++\n");
}

void hit_or_stand(cardlist_t *deck,cardlist_t *player_hand,unsigned int *pot_return)
{
    while (1)
    {
        char c;
        printf("Do you wanna hit (press y) or stand press (press n) \n");
        scanf(" %c", &c);
        fflush(stdin);
        fflush(stdout);
    switch (c)
    {
        case 'n':
            return;
        case 'y':
            getting_card_player(deck, player_hand);

            print_player_deck(player_hand);

            print_player_score(player_hand);

            bool bust = is_bust(player_hand);
            if (bust == 1) {
                is_bust_check(pot_return);
                return;
            }
            break;
        default:
            printf("please try again only -> y/n\n");
            break;
        }
    }
}

void is_bust_check(unsigned int *pot_return)
{
    *pot_return = 0;
    print_bust();
}

void print_dealer_score(cardlist_t *dealer_hand)
{
    unsigned int dealer_score = return_sum(dealer_hand);
    printf("\n");
    printf("++++++++++++++++++++++++++++++\n");
    printf("dealer score -> %u\n",dealer_score);
    printf("++++++++++++++++++++++++++++++\n");
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

void print_status_print(unsigned int c, unsigned int p)
{
    printf("===========================================\n");
    printf("\t\t Cash:%u ,Pot:%u \n",c,p);
    printf("===========================================\n");
}