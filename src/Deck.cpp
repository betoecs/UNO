#include "Deck.hpp"
#include <math.h>

///////////////////////////////////////
Deck::Deck () : top(0)
{
    int index = 0;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                cards [index].setColor(Card::Color(i));
                cards [index].setSymbol(Card::Symbol(j));
                index++;
            }
        }
    }

    for (int i = 0; i < 4; i++)
    {
        cards [index].setColor(Card::Color(i));
        cards [index].setSymbol(Card::Symbol(0));
        index++;
    }

    mix();
}

///////////////////////////////////////
void Deck::mix()
{
    for (int i = 0; i < 78; i++)
    {
        Card out;
        int random = rand() % 79;

        out = cards [i];
        cards [i] = cards [random];
        cards [random] = out;
    }
}

///////////////////////////////////////
Card * Deck::getCard()
{
    Card *card = &cards [top];
    card->setUsed(true);
    top++;

    return card;
}
