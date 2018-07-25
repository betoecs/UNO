#ifndef CARD_ENTITY_HPP
#define CARD_ENTITY_HPP

#include "Card.hpp"
#include <LK/Sprite.hpp>
using namespace lk;

class CardEntity : public Sprite
{
public:
	Card * getCard();
	void setCard(Card *card);
	CardEntity(Card *card, bool faceDown);

private:
	bool faceDown;
	Card *card;
};

#endif // CARD_ENTITY_HPP
