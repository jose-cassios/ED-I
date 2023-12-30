#include <iostream>
#include <string>
#include <random>
#include <chrono>
using namespace std;

//Number of players and cards
const int numPlayers {4};
const int numCards {numPlayers*5};

// Structure for cards
struct Card {
    int value;
    int suit;
};

// Structure for players
struct Player {
    char name[20];
    Card *cards;
};

// Array to hold card descriptions
const char *array[13] {
    "Ace of", "Two of", "Three of", "Four of", "Five of", "Six of",
    "Seven of", "Eight of", "Nine of", "Ten of", "Jack of", "Queen of", "King of"
};

// Matrix to track drawn cards
int matrix[4][13] {0};

// Function to check if a card has been drawn
int drawn_cards(int value, int suit, int matrix[4][13]){
    return matrix[suit][value];
}

// Function to get suit name based on integer value
const char* suit(Card *c){
    switch (c->suit) {
    case 0:
        return "Hearts";

    case 1:
        return "Spades";

    case 2:
        return "Clubs";

    case 3:
        return "Diamonds";

    default:
        return "Invalid";
    }
}

// Function to read players and deal cards
void read_players(Player *players, Card *cards){
    // Initializing the random seed for card shuffling
    auto seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator(static_cast<unsigned>(seed));

    for (int i = 0; i < numPlayers; i++){
        cout << "Insert the name of player " << i+1 << ": ";
        cin.getline(players[i].name, 20);

        // Assign cards to the player
        players[i].cards = cards + i * 5;

        for (int j = 0; j < 5; j++){
            uniform_int_distribution<int> value_distribution(0, 12);
            uniform_int_distribution<int> suit_distribution(0, 3);

            int suit, value;

            do {
                value = value_distribution(generator);
                suit = suit_distribution(generator);

            } while (drawn_cards(value, suit, matrix));
            
            matrix[suit][value] = 1;

            players[i].cards[j].value = value;
            players[i].cards[j].suit = suit;

        }
    }
}

// Function to display players and their cards
void show_players(Player *players){
    for (int i = 0; i < numPlayers; i++){
        cout << "\n[ " << players[i].name << " ] - ";
        for(int j = 0; j < 5; j++) {
            cout << array[players[i].cards[j].value] << " ";
            cout << suit(&players[i].cards[j]) << " ";
        }
        cout << "\n";
    }
}
