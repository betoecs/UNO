#include "Card.hpp"

///////////////////////////////////////
Card::Card(Color color, Symbol symbol) : color(color), symbol(symbol), used(false)
{
}

///////////////////////////////////////
bool Card::isUsed() const
{
    return used;
}

///////////////////////////////////////
void Card::setUsed(bool used)
{
    this->used = used;
}

///////////////////////////////////////
Card::Color Card::getColor() const
{
    return color;
}

///////////////////////////////////////
Symbol Card::getSymbol() const
{
    return symbol;
}

///////////////////////////////////////
Card::Compatibility Card::getCompatibility(const Card &card) const
{
    if (card.symbol == symbol && card.color == color)
        return Two;

    if (card.symbol == symbol || card.color == color)
        return One;

    return None;
}
