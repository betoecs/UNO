#include "Card.hpp"

///////////////////////////////////////
Card::Card(Color color, Symbol symbol) : color(color), symbol(symbol), used(false)
{
}

///////////////////////////////////////
bool Card::isUsed()
{
    return used;
}

///////////////////////////////////////
void Card::setUsed(bool used)
{
    this->used = used;
}

///////////////////////////////////////
Compatibility Card::getCompatibility(const Card &card)
{
    if (card.symbol == symbol && card.color == color)
        return Two;

    if (card.symbol == symbol || card.color == color)
        return One;

    return None;
}
