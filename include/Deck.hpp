#ifndef DECK_HPP
#define DECK_HPP

#include "Card.hpp"

class Deck
{
public:
    Deck();
    void mix();
    Card * getCard();

private:
    int top;
    Card cards [78];
};

#endif // DECK_HPP
