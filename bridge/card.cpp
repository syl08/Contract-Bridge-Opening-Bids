#include <iostream>
#include "card.h"

/// No args constructor.
Card::Card()
{
}

/// Constructor that sets the rank and suit for a Card object.
Card::Card(Rank rank,Suit suit)
{
    cardRank = rank;
    cardSuit = suit;
}

/// Constructor that sets the rank and suit for a Card object from an input string.
Card::Card(string card)
{
    // get card rank
    switch (card[0])
    {
    case '2':
        cardRank = TWO;
        break;
    case '3':
        cardRank = THREE;
        break;
    case '4':
        cardRank = FOUR;
        break;
    case '5':
        cardRank = FIVE;
        break;
    case '6':
        cardRank = SIX;
        break;
    case '7':
        cardRank = SEVEN;
        break;
    case '8':
        cardRank = EIGHT;
        break;
    case '9':
        cardRank = NINE;
        break;
    case 'T':
        cardRank = TEN;
        break;
    case 'J':
        cardRank = JACK;
        break;
    case 'Q':
        cardRank = QUEEN;
        break;
    case 'K':
        cardRank = KING;
        break;
    case 'A':
        cardRank = ACE;
        break;
    }

    // get card suit
    switch (card[1])
    {
    case 'S':
        cardSuit = SPADES;
        break;
    case 'H':
        cardSuit = HEARTS;
        break;
    case 'D':
        cardSuit = DIAMONDS;
        break;
    case 'C':
        cardSuit = CLUBS;
        break;
    }
}

/// Destructor.
Card::~Card()
{
}

/// Card rank accessor.
Rank Card::getRank()
{
    return cardRank;
}

/// Card suit accessor.
Suit Card::getSuit()
{
    return cardSuit;
}

/// Overloads the function operator to provide a comparison which sets
/// an ordering between two Card objects.
bool Card::operator()(Card* leftCard,Card* rightCard)
{
    if(leftCard->getSuit() == rightCard->getSuit())
        return leftCard->getRank() > rightCard->getRank();

    return leftCard->getSuit() > rightCard->getSuit();
}

/// Overload the << operator so that a string representation of Card can be output.
ostream& operator<<(ostream& out, Card& card)
{
    switch (card.cardRank)
    {
    case TWO:
        cout << "2";
        break;
    case THREE:
        cout << "3";
        break;
    case FOUR:
        cout << "4";
        break;
    case FIVE:
        cout << "5";
        break;
    case SIX:
        cout << "6";
        break;
    case SEVEN:
        cout << "7";
        break;
    case EIGHT:
        cout << "8";
        break;
    case NINE:
        cout << "9";
        break;
    case TEN:
        cout << "T";
        break;
    case JACK:
        cout << "J";
        break;
    case QUEEN:
        cout << "Q";
        break;
    case KING:
        cout << "K";
        break;
    case ACE:
        cout << "A";
        break;
    }

    switch (card.cardSuit)
    {
    case CLUBS:
        cout << "C";
        break;
    case DIAMONDS:
        cout << "D";
        break;
    case HEARTS:
        cout << "H";
        break;
    case SPADES:
        cout << "S";
        break;
    }
    return out;
}

