#ifndef HAND_H_INCLUDED
#define HAND_H_INCLUDED

#include <string>
#include <set>
#include "card.h"

using namespace std;

/// The Hand class is responsible for, among other things, storing the cards
/// dealt to a particular player. Also for determining the bid.
class Hand
{
public:

    /// No arguments constructor.
    Hand();

    /// Destructor.
    ~Hand();

    /// Clears all of suit collections.
    void clear();

    /// Adds a Card* to the Hand placing the card with other cards of the same suit.
    void addCard(Card*);

    /// Responsible for implementing the bidding logic.
    string makeBid();

    /// Puts a string representation of a hand on the output stream.
    friend ostream& operator<<(ostream& out,Hand& hand);

private:

    // store hand cards in 4 suits and order them
    set<Card*,Card> clubsCard;
    set<Card*,Card> heartsCard;
    set<Card*,Card> diamondsCard;
    set<Card*,Card> spadesCard;

    // store high cards points
    int highCardPoint;

    static const int ACE_POINT = 4;
    static const int KING_POINT = 3;
    static const int QUEEN_POINT = 2;
    static const int JACK_POINT = 1;
    static const int ZERO_POINT = 0;
    static const int HAND_CARDS = 13;

    /// check cards shape
    bool handBalenced();

    /// calculate card length points
    int lengthPoints();

    /// calculate high card points
    int hightCardPoints();

    /// calculate strength
    int totalStrength();
};


#endif // HAND_H_INCLUDED
