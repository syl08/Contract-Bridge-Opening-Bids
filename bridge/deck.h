#ifndef DECK_H_INCLUDED
#define DECK_H_INCLUDED

#include "card.h"
#include "random.h"

/// Consist of a dynamic array of Card object and initialize all cards.
class Deck
{
public:

    /// No Argument construct.
    Deck();

    /// Destructor.
    ~Deck();

    /// Sets cardsDealt to 0.
    void reset();

    /// Returns a pointer to the next Card object from the deck.
    Card* dealNextCard();

    /// Shuffles the cards in the deck.
    void shuffle();

    /// Puts a string representation of Card objects in the deck.
    friend ostream& operator<<(ostream& out,Deck& deck);

    /// Reads strings from input stream and each string represents a card.
    friend istream& operator>>(istream& in,Deck& deck);

private:
    static const int CARD_NUMBER = 52;
    static const int CARD_SUIT = 4;
    static const int CARD_RANK = 13;
    Card *cardDeck;
    int cardsDealt;
};













#endif // DECK_H_INCLUDED
