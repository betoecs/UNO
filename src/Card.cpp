#include "Card.hpp"
#include <stdio.h>

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
    if ((card.symbol == symbol && (card.color == color || card.color == Card::NoColor)) || card.symbol == Wild || card.symbol == Take4)
        return Two;

    if (card.symbol == symbol || (card.color == color || card.color == Card::NoColor))
        return One;

    return None;
}

///////////////////////////////////////
std::string Card::toString() const
{
	std::string string;
	if (color != NoColor)
	{
		string = colorToString(color);
		string += " ";
	}

    switch (symbol)
    {
        case GamePad:   string += "GamePad"; break;
        case Apple:     string += "Appel"; break;
        case Github:    string += "Github"; break;
        case Leaf:      string += "Leaf"; break;
        case Brush:     string += "Brush"; break;
        case Paw:       string += "Paw"; break;
        case Star:      string += "Star"; break;
        case Bird:		string += "Bird"; break;
		case Rocket:	string += "Rocket"; break;
		case Heart:		string += "Heart"; break;
		case Skip:		string += "Skip"; break;
		case Reverse:	string += "Reverse"; break;
		case Take2:		string += "Take2"; break;
		case Take4:		return "Take4";
		case Wild:		return "Wild";
    }

	return string;
}

///////////////////////////////////////
std::string colorToString(Card::Color color)
{
	switch (color)
	{
		case Card::Red:	 	return "Red";
		case Card::Green:	return "Green";
		case Card::Blue:	return "Blue";
		case Card::Yellow: 	return "Yellow";
		case Card::NoColor:	return "No Color";
	}
}
