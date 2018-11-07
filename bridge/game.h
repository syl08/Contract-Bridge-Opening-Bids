#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include <string>
#include "deck.h"
#include "hand.h"

/* Enumeration for players' position. First dealer is NORTH */
enum Position {NORTH, EAST, SOUTH, WEST};

/// The Game class should hold the Deck object for the game and hold
/// an array of Hand and keep track of which Position is currently the
/// dealer. It also store the opening bid and who made the bid.
class Game
{
public:

    /// No argument constructor.
    Game();

    /// Destructor.
    ~Game();

    /// Check the input, if true call the reset method on the deck and
    /// clears each Hand. If false shuffle the deck.
    void setup(bool fromFile);

    /// Deals the cards from the deck
    void deal();

    /// Starting with the dealer, calls makeBid() to see what bid
    /// is made.
    void auction();

    /// Increments the dealer Position to the next player.
    void nextDealer();

    /// Puts a string representation of the game onto the output stream.
    friend ostream& operator<<(ostream& out, Game& game);

    /// Passes the input stream onto the deck
    friend istream& operator>>(istream& in, Game& game);


private:
    Position dealer;
    Deck gameDeck;
    Hand* gameHand;
    static const int GAME_HAND = 4;
    static const int GAME_HAND_CARDS = 13;

    /// store the bid result.
    int bidResult;

    /// transfer position with index to a string.
    string toPositon(int);
};











#endif // GAME_H_INCLUDED
