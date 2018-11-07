#include <iostream>
#include <iomanip>
#include "hand.h"

using namespace std;

/// No arguments constructor. Sets highCardPoint to 0.
Hand::Hand()
{
    highCardPoint = 0;
}

/// Deletes each Card* in the Hand.
Hand::~Hand()
{
    spadesCard.clear();
    heartsCard.clear();
    clubsCard.clear();
    diamondsCard.clear();
}

/// Clears all of the suit collections. Reset highCardPoint to 0.
void Hand::clear()
{
    highCardPoint = 0;
    spadesCard.clear();
    heartsCard.clear();
    clubsCard.clear();
    diamondsCard.clear();
}

/// Adds a Card* to the Hand placing the card with other cards of the same suit.
/// Calculate the high card point and store it in highCardPoint.
void Hand::addCard(Card* card)
{

    // store card in the suit collections
    switch (card->getSuit())
    {
    case SPADES:
        spadesCard.insert(card);
        break;
    case HEARTS:
        heartsCard.insert(card);
        break;
    case DIAMONDS:
        diamondsCard.insert(card);
        break;
    case CLUBS:
        clubsCard.insert(card);
        break;
    }

    // calculate high card points
    switch (card->getRank())
    {
    case ACE:
        highCardPoint += ACE_POINT;
        break;
    case KING:
        highCardPoint += KING_POINT;
        break;
    case QUEEN:
        highCardPoint += QUEEN_POINT;
        break;
    case JACK:
        highCardPoint += JACK_POINT;
        break;
    default:
        highCardPoint += ZERO_POINT;
    }
}

/// Responsible for implementing the bidding logic and for deciding on
/// the bid to be made for this hand.
string Hand::makeBid()
{
    if(handBalenced() == true)
    {
        if(totalStrength() >= 0 && totalStrength() <= 12)
        {
            return "PASS";
        }
        else if(totalStrength() >= 13 && totalStrength() <= 14)
        {
            if(diamondsCard.size() == 4 && clubsCard.size() == 4)
            {
                return "1D";
            }
            else if(diamondsCard.size() == 3 && clubsCard.size() == 3)
            {
                return "1C";
            }
            else if(diamondsCard.size() > clubsCard.size())
            {
                return "1D";
            }
            else if(diamondsCard.size() < clubsCard.size())
            {
                return "1C";
            }
        }
        else if(totalStrength() >= 15 && totalStrength() <= 17)
        {
            return "1 NT";
        }
        else if(totalStrength() >= 18 && totalStrength() <= 19)
        {
            if(diamondsCard.size() == 4 && clubsCard.size() == 4)
            {
                return "1D";
            }
            else if(diamondsCard.size() == 3 && clubsCard.size() == 3)
            {
                return "1C";
            }
            else if(diamondsCard.size() > clubsCard.size())
            {
                return "1D";
            }
            else if(diamondsCard.size() < clubsCard.size())
            {
                return "1C";
            }
        }
        else if(totalStrength() >= 20 && totalStrength() <= 21)
        {
            return "2 NT";
        }
        else
        {
            return "2C";
        }
    }
    else
    {
        if(totalStrength() >=0 && totalStrength() <= 12)
        {
            if(spadesCard.size() == 6 && heartsCard.size() < 6 && diamondsCard.size() < 6 && clubsCard.size() < 6)
            {
                return "2S";
            }
            else if(spadesCard.size() < 6 && heartsCard.size() == 6 && diamondsCard.size() < 6 && clubsCard.size() < 6)
            {
                return "2H";
            }
            else if(spadesCard.size() < 6 && heartsCard.size() < 6 && diamondsCard.size() == 6 && clubsCard.size() < 6)
            {
                return "2D";
            }
            else if(spadesCard.size() < 6 && heartsCard.size() < 6 && diamondsCard.size() < 6 && clubsCard.size() == 6)
            {
                return "PASS";
            }
            else if(spadesCard.size() == 6 && heartsCard.size() == 6)
            {
                return "2S";
            }
            else if(spadesCard.size() == 6 && diamondsCard.size() == 6)
            {
                return "2S";
            }
            else if(spadesCard.size() == 6 && clubsCard.size() == 6)
            {
                return "2S";
            }
            else if(heartsCard.size() == 6 && diamondsCard.size() == 6)
            {
                return "2H";
            }
            else if(heartsCard.size() == 6 && clubsCard.size() == 6)
            {
                return "2H";
            }
            else if(diamondsCard.size() == 6 && clubsCard.size() == 6)
            {
                return "2D";
            }
            else if(spadesCard.size() == 7)
            {
                return "3S";
            }
            else if(heartsCard.size() == 7)
            {
                return "3H";
            }
            else if(diamondsCard.size() == 7)
            {
                return "3D";
            }
            else if(clubsCard.size() == 7)
            {
                return "3C";
            }
            else if(spadesCard.size() == 8)
            {
                return "4S";
            }
            else if(heartsCard.size() == 8)
            {
                return "4H";
            }
            else if(diamondsCard.size() == 8)
            {
                return "4D";
            }
            else if(clubsCard.size() == 8)
            {
                return "4C";
            }
            else
            {
                return "PASS";
            }
        }
        else if(totalStrength() >= 13 && totalStrength() <= 21)
        {
            if(spadesCard.size() > heartsCard.size() && spadesCard.size() > diamondsCard.size() && spadesCard.size() > clubsCard.size())
            {
                return "1S";
            }
            else if(heartsCard.size() > spadesCard.size() && heartsCard.size() > diamondsCard.size() && heartsCard.size() > clubsCard.size())
            {
                return "1H";
            }
            else if(diamondsCard.size() > spadesCard.size() && diamondsCard.size() > heartsCard.size() && diamondsCard.size() > clubsCard.size())
            {
                return "1D";
            }
            else if(clubsCard.size() > spadesCard.size() && clubsCard.size() > heartsCard.size() && clubsCard.size() > diamondsCard.size())
            {
                return "1C";
            }
            else if(spadesCard.size() >= 5 && spadesCard.size() == heartsCard.size())
            {
                return "1S";
            }
            else if(spadesCard.size() >= 5 && spadesCard.size() == diamondsCard.size())
            {
                return "1S";
            }
            else if(spadesCard.size() >= 5 && spadesCard.size() == clubsCard.size())
            {
                return "1S";
            }
            else if(heartsCard.size() >= 5 && heartsCard.size() == diamondsCard.size())
            {
                return "1H";
            }
            else if(heartsCard.size() >= 5 && heartsCard.size() == clubsCard.size())
            {
                return "1H";
            }
            else if(diamondsCard.size() >=5 && diamondsCard.size() == clubsCard.size())
            {
                return "1D";
            }
            else if(spadesCard.size() == 4 && spadesCard.size() == heartsCard.size() && spadesCard.size() == diamondsCard.size())
            {
                return "1D";
            }
            else if(spadesCard.size() == 4 && spadesCard.size() == heartsCard.size() && spadesCard.size() == clubsCard.size())
            {
                return "1C";
            }
            else if(spadesCard.size() == 4 && spadesCard.size() == diamondsCard.size() && spadesCard.size() == clubsCard.size())
            {
                return "1C";
            }
            else if(heartsCard.size() == 4 && heartsCard.size() == diamondsCard.size() && heartsCard.size() == clubsCard.size())
            {
                return "1C";
            }
        }
        else
        {
            return "2C";
        }
    }
}

/// Overload the << operator so that a string representation
/// of a Hand can be output on the stream.
ostream& operator<<(ostream& out, Hand& hand)
{
    cout << "Spades   :";

    for(set<Card*>::iterator its = hand.spadesCard.begin(); its != hand.spadesCard.end(); ++its)
    {
        cout << setw(2) << **its;
    }
    cout << endl;
    cout << "Hearts   :";

    for(set<Card*>::iterator ith = hand.heartsCard.begin(); ith != hand.heartsCard.end(); ++ith)
    {
        cout << setw(2) << **ith;
    }
    cout << endl;
    cout << "Diamonds :";

    for(set<Card*>::iterator itd = hand.diamondsCard.begin(); itd != hand.diamondsCard.end(); ++itd)
    {
        cout << setw(2) << **itd;
    }
    cout << endl;
    cout << "Clubs    :";

    for(set<Card*>::iterator itc = hand.clubsCard.begin(); itc != hand.clubsCard.end(); ++itc)
    {
        cout << setw(2) << **itc;
    }
    cout << endl;
    return out;
}

/// Calculate the card length points.
int Hand::lengthPoints()
{
    int lengthPoints = 0;

    if(spadesCard.size() > 4)
        lengthPoints += (spadesCard.size() - 4);

    if(heartsCard.size() > 4)
        lengthPoints += (heartsCard.size() - 4);

    if(diamondsCard.size() > 4)
        lengthPoints += (diamondsCard.size() - 4);

    if(clubsCard.size() > 4)
        lengthPoints += (clubsCard.size() - 4);

    return lengthPoints;
}

/// Calculate the high card points.
int Hand::hightCardPoints()
{
    return highCardPoint;
}

/// Calculate the strength.
int Hand::totalStrength()
{
    int total = 0;
    total = lengthPoints() + hightCardPoints();
    return total;
}

/// Evaluate the cards shape.
bool Hand::handBalenced()
{
    if(spadesCard.size() == 0 || heartsCard.size() == 0 || diamondsCard.size() == 0 || clubsCard.size() == 0)
    {
        return false;
    }
    else if(spadesCard.size() == 1 || heartsCard.size() == 1 || diamondsCard.size() == 1 || clubsCard.size() == 1)
    {
        return false;
    }
    else if(spadesCard.size() >= 5 || heartsCard.size() >= 5 || diamondsCard.size() >= 5 || clubsCard.size() >= 5)
    {
        return false;
    }
    else
    {
        return true;
    }
}
