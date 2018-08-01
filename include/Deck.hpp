#ifndef DECK_HPP
#define DECK_HPP

#include "Card.hpp"

class Deck
{
public:
    Deck();
    void reset();
    void mix();
    Card * getCard();

private:
    int top;
    Card cards [110];
};

#endif // DECK_HPP
