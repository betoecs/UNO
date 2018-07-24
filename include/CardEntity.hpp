#ifndef CARD_ENTITY_HPP
#define CARD_ENTITY_HPP

#include "Card.hpp"
#include <LK/Sprite.hpp>
using namespace lk;

class CardEntity : public Sprite
{
public:
	CardEntity(Card *card, bool faceDown);
	void setCard(Card *card);
	const Card * getCard() const;

private:
	bool faceDown;
	Card *card;
};

#endif // CARD_ENTITY_HPP
