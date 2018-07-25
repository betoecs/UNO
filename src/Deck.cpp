#include "Deck.hpp"
#include <math.h>
#include <stdio.h>

///////////////////////////////////////
Deck::Deck () : top(0)
{
    int index = 0;

	// 2 cards of each color for symbols from Appel to Take2
    for (int i = 0; i < 4; i++)
    {
        for (int j = 1; j < 13; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                cards [index].setColor(Card::Color(i));
                cards [index].setSymbol(Card::Symbol(j));
                index++;
            }
        }
    }

	// 1 card of each color for GamePad
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
	if (top >= 102)
		top = 0;

    Card *card;
	do
	{
		card = &cards [top];
		top++;
	} while (card->isUsed());

	card->setUsed(true);
    return card;
}
