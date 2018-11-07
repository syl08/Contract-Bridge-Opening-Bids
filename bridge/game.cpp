#include <iostream>
#include "game.h"

using namespace std;

/// No argument constructor, initialize the dynamic array of
/// Hand, sets dealer to NORTH.
Game::Game()
{
    gameHand = new Hand[GAME_HAND];
    dealer = NORTH;
}

/// Destructor responsible for discarding the array.
Game::~Game()
{
    delete[] gameHand;
}


/// Check the input file, if true call the reset method on the deck
/// and clears each Hand, otherwise shuffle the deck, then call the
/// reset method and clears each Hand.
void Game::setup(bool fromFile)
{
    if(fromFile == false)
        gameDeck.shuffle();

    gameDeck.reset();

    for(int i = 0; i < 4; i++)
    {
        gameHand[i].clear();
    }
}

/// Deals the cards from the deck clockwise to each player in turn
/// starting with the player on the dealer's left.
void Game::deal()
{
    for(int i = 0; i < GAME_HAND_CARDS; i++)
    {
        gameHand[(dealer + 1) % 4].addCard(gameDeck.dealNextCard());
        gameHand[(dealer + 2) % 4].addCard(gameDeck.dealNextCard());
        gameHand[(dealer + 3) % 4].addCard(gameDeck.dealNextCard());
        gameHand[dealer % 4].addCard(gameDeck.dealNextCard());
    }
}

/// Starting with dealer, calls makeBid() to see what bid is made. If a bid other
/// than Pass is received from the current Hand, the auction can stop.
void Game::auction()
{
    if(gameHand[dealer % 4].makeBid() != "PASS")
    {
        gameHand[dealer % 4].makeBid();
        bidResult = 1;
    }
    else
    {
        if(gameHand[(dealer + 1) % 4].makeBid() != "PASS")
        {
            gameHand[(dealer + 1) % 4].makeBid();
            bidResult = 2;
        }
        else
        {
            if(gameHand[(dealer + 2) % 4].makeBid() != "PASS")
            {
                gameHand[(dealer + 2) % 4].makeBid();
                bidResult = 3;
            }
            else
            {
                if(gameHand[(dealer + 3) % 4].makeBid() != "PASS")
                {
                    gameHand[(dealer + 3) % 4].makeBid();
                    bidResult = 4;
                }
                else
                {
                    bidResult = 5;
                }
            }
        }
    }
}

/// Increments the dealer Position to the next player.
void Game::nextDealer()
{
    dealer = Position((dealer + 1) % 4);
}

/// Overload the << operator so that a string representation of game
/// can be output on the stream.
ostream& operator<<(ostream& out, Game& game)
{
    cout << game.toPositon(game.dealer % 4) << endl;
    cout << game.gameHand[game.dealer % 4] << endl;
    cout << game.toPositon((game.dealer + 1) % 4) << endl;
    cout << game.gameHand[(game.dealer + 1) % 4] << endl;
    cout << game.toPositon((game.dealer + 2) % 4) << endl;
    cout << game.gameHand[(game.dealer + 2) % 4] << endl;
    cout << game.toPositon((game.dealer + 3) % 4) << endl;
    cout << game.gameHand[(game.dealer + 3) % 4] << endl;
    cout << endl;

    if(game.bidResult == 1)
    {
        cout << "Opening Bid is " << game.gameHand[game.dealer % 4].makeBid() << " made by " << game.toPositon(game.dealer % 4);
    }
    else if(game.bidResult == 2)
    {
        cout << "Opening Bid is " << game.gameHand[(game.dealer + 1) % 4].makeBid() << " made by " << game.toPositon((game.dealer + 1) % 4);
    }
    else if(game.bidResult == 3)
    {
        cout << "Opening Bid is " << game.gameHand[(game.dealer + 2) % 4].makeBid() << " made by " << game.toPositon((game.dealer + 2) % 4);
    }
    else if(game.bidResult == 4)
    {
        cout << "Opening Bid is " << game.gameHand[(game.dealer + 3) % 4].makeBid() << " made by " << game.toPositon((game.dealer + 3) % 4);
    }
    else if(game.bidResult == 5)
    {
        cout << "All hands PASS";
    }
    return out;
}

/// Overload the >> operator so that the input stream can be passed
/// onto the deck.
istream& operator>>(istream& in, Game& game)
{
    in >> game.gameDeck;
    return in;
}

/// Transfer position index number to a string
string Game::toPositon(int positionNumber)
{
    switch(positionNumber)
    {
    case 0:
        return "NORTH";
        break;
    case 1:
        return "EAST";
        break;
    case 2:
        return "SOUTH";
        break;
    case 3:
        return "WEST";
        break;
    default:
        return "Error";
    }
}

