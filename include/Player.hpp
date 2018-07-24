#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Card.hpp"

#include <LK/Entity.hpp>
#include <LK/LinearLayout.hpp>
using namespace lk;

class Player : public Entity
{
public:
	Player();
	void addCard(Card *card, bool faceDown);

private:
	LinearLayout *cardsLayout;
};

#endif // PLAYER_HPP
