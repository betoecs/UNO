#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Card.hpp"
#include "CardEntity.hpp"

#include <vector>
#include <LK/Entity.hpp>
#include <LK/LinearLayout.hpp>

using namespace lk;

class Player : public Entity
{
public:
	Player();
	void removeCard(CardEntity *card);
	void addCard(Card *card, bool faceDown);
	const std::vector <CardEntity *> & getCards() const;

private:
	std::vector <CardEntity *> cards;
	LinearLayout *cardsLayout;
};

#endif // PLAYER_HPP
