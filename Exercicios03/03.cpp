#include "03.hpp"

extern const int numPlayers;
extern const int numCards;

int main() {
    srand(time(NULL)); // Initializes the random seed for each code initialization.

    // Allocating memory for players and cards
    Card *cards = new Card[numCards];
    Player *players = new Player[numPlayers];

    // Reading players and dealing cards
    read_players(players, cards);

    // Displaying players' cards
    show_players(players);

    // Deallocating memory
    delete[] players;
    delete[] cards;

    return 0;
}
