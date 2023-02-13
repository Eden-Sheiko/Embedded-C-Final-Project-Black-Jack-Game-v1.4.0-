# Embedded C Final Project: Black-Jack Game (v1.4.0)
terminal-based Black-Jack game between a human player and a computer-controlled dealer.

# Card representation
The game uses playing cards that are represented by a Card struct that stores its values and serves as a node in a singly linked list.
Each card has two fields: data and next.

data: Represents the values of the card stored in a uint8_t, with the first two bits [1:0] representing the suit, the next four bits [5:2] representing the rank, and the remaining bits [7:6] unused.

suit: A suit can have one of the following values: Spades, Hearts, Clubs, and Diamonds. The suit is not a field on its own, but is instead coded inside the data.

rank: A rank can have one of the following values: Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King. The rank is not a field on its own, but is instead coded inside the data.

next: The game utilizes a singly linked list of Card structs, where each card is linked to the next card using a Card pointer called next.

value: Each card has a value that can be determined from its rank. Ranks 2-10 have their face values (rank 2 has a value of 2, rank 3 has a value of 3, etc.). The values of the "royalty" ranks Jack, Queen, and King are always 10. The value of an Ace is 1.


# Deck and Hands representation

Every deck and hand in the game is represented as a linked list of cards, using the CardList struct. It contains the following fields:

head: Points to the first card in the list. An empty list is represented with a head pointing to NULL.
len: A size_t that represents the size of the linked list and must be properly modified.
The game starts with a single shared deck of cards that contains all possible cards (order does not matter). The dealer and player each have their own empty list at the beginning of each game, which gets filled as the game progresses by pulling cards from the deck and inserting them into their hands. When the game ends, the cards in both hands are placed back into the deck.
