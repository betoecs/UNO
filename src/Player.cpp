#include "Player.hpp"
#include "CardEntity.hpp"

///////////////////////////////////////
Player::Player(Deck *deck) : deck(deck)
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

///////////////////////////////////////
void Player::removeCard(CardEntity *card)
{
	for (auto it = cards.begin(); it != cards.end(); ++it)
	{
		if (*it == card)
		{
			cards.erase(it);
			break;
		}
	}
	card->release();
}

///////////////////////////////////////
bool Player::hasCards() const
{
	return cards.size();
}

///////////////////////////////////////
void Player::take(int number)
{
	for (int i = 0; i < number; i++)
		addCard(deck->getCard(), false);
}
