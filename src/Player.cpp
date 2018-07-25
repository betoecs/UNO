#include "Player.hpp"
#include "CardEntity.hpp"

///////////////////////////////////////
Player::Player()
{
	cardsLayout = new LinearLayout(20);
	addChild(cardsLayout);
}

///////////////////////////////////////
void Player::addCard(Card *card, bool faceDown)
{
	CardEntity *newCard = new CardEntity(card, faceDown);
	cardsLayout->addChild(newCard);
	cards.push_back(newCard);
}

///////////////////////////////////////
const std::vector <CardEntity *> & Player::getCards() const
{
	return cards;
}
