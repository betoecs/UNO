#include "Card.hpp"

///////////////////////////////////////
Card::Card() : used(false)
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
Card::Symbol Card::getSymbol() const
{
    return symbol;
}

///////////////////////////////////////
void Card::setColor(Color color)
{
    this->color = color;
}

///////////////////////////////////////
void Card::setSymbol(Symbol symbol)
{
    this->symbol = symbol;
}

///////////////////////////////////////
Card::Compatibility Card::getCompatibility(const Card &card) const
{
    if ((card.symbol == symbol && card.color == color) || card.symbol == Wild || card.symbol == Take4)
        return Two;

    if (card.symbol == symbol || card.color == color)
        return One;

    return None;
}
