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
		setTexture("cards/" + std::to_string(card->getSymbol()) + std::to_string(card->getColor()) + ".png");

	setOriginCenter();
}

///////////////////////////////////////
Card * CardEntity::getCard()
{
	return card;
}
