#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED

using namespace std;

/* Enumeration for cards' rank. Rank two is the lowest level */
enum Rank
{
    TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE
};

/* Enumeration for cards' suit. Clubs is the highest level */
enum Suit {CLUBS, DIAMONDS, HEARTS, SPADES};

/// Encapsulates rank and suit for a card object.
class Card
{
public:

    /// No argument constructor.
    Card();

    /// Constructor that sets the rank and suit for a card object.
    Card(Rank, Suit);

    /// Constructor that sets the rank and suit for a card object from an input string.
    Card(string);

    /// Destructor.
    ~Card();

    /// Accessor for the Rank instance variable.
    Rank getRank();

    /// Accessor for the Suit instance variable.
    Suit getSuit();

    /// Overloads the function operator to order two card objects.
    bool operator()(Card*,Card*);

    /// Puts a string representation of this card on the output stream.
    friend ostream& operator<<(ostream& out,Card& card);

private:
    Rank cardRank;
    Suit cardSuit;
};


#endif // CARD_H_INCLUDED
