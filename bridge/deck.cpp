#include <iostream>
#include <iomanip>
#include <string>
#include "deck.h"

using namespace std;

/// No Argument constructor. Creates a dynamically allocated array of
/// Card* objects and initializes them. Initializes cardsDealt to 0.
Deck::Deck()
{
    cardDeck = new Card[CARD_NUMBER];
    int index = 0;

    for(int suit = 0; suit < CARD_SUIT; suit++)
    {
        for(int rank = 0; rank < CARD_RANK; rank++)
        {
            cardDeck[index] = Card((Rank)rank,(Suit)suit);
            index++;
        }
    }
    cardsDealt = 0;
}

/// Destructor, deletes the contents of the array of Card*.
Deck::~Deck()
{
    delete[] cardDeck;
}

/// Sets cardsDealt to 0.
void Deck::reset()
{
    cardsDealt = 0;
}

/// Returns a pointer to the next Card object from the deck, increments cardsDealt.
Card* Deck::dealNextCard()
{
    Card* nextCard = &cardDeck[cardsDealt];
    cardsDealt++;
    return nextCard;
}

/// Shuffles the cards in the deck. Selecting two random indexes in the
/// array and swapping the references around, putting the cards out of
/// their original order.
void Deck::shuffle()
{
    Random rand;
    int left, right;

    for(int i = 0; i < CARD_NUMBER; i++)
    {
        left = rand.randomInteger(0,CARD_NUMBER - 1);
        right = rand.randomInteger(0,CARD_NUMBER - 1);
        swap(cardDeck[left],cardDeck[right]);
    }
}

/// Overload the << operator so that a string representation of Card
/// objects in the deck can be output.
ostream& operator<<(ostream& out,Deck& deck)
{
    for(int i = 0; i < deck.CARD_NUMBER; i++)
    {
        if(i%13 == 0 && i != 0)
            cout << endl;
        cout << setw(3) << deck.cardDeck[i];
    }
    return out;
}

/// Overload the >> operator so that 52 strings from an input stream can
/// be read, where each string represents a card.
istream& operator>>(istream& in,Deck& deck)
{
    for (int i = 0; i < deck.CARD_NUMBER; i++)
    {
        string inputCard;
        in >> inputCard;

        Card* card = new Card(inputCard);
        deck.cardDeck[i] = *card;
    }
    return in;
}
