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
	cardsLayout->addChild(new CardEntity(card, faceDown));
}
