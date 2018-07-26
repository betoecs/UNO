#include "CardEntity.hpp"

///////////////////////////////////////
CardEntity::CardEntity(Card *card, bool faceDown) : faceDown(faceDown)
{
	setCard(card);
}

///////////////////////////////////////
void CardEntity::setCard(Card *card)
{
	this->card = card;

	if (faceDown)
		setTexture("cards/card_back.png");
	else if (card)
	{

		std::string cardName = std::to_string(card->getSymbol());
		if (card->getSymbol() != Card::Wild && card->getSymbol() != Card::Take4)
		 	cardName += std::to_string(card->getColor());
		setTexture("cards/" + cardName + ".png");
	}

	setOriginCenter();
}

///////////////////////////////////////
Card * CardEntity::getCard()
{
	return card;
}
