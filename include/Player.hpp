#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Card.hpp"
#include "CardEntity.hpp"
#include "Deck.hpp"

#include <vector>
#include <LK/Entity.hpp>
#include <LK/LinearLayout.hpp>

using namespace lk;

class Player : public Entity
{
public:
	Player(Deck *deck);
	void addCard(Card *card, bool faceDown);
	const std::vector <CardEntity *> & getCards() const;
	bool hasCards() const;
	void removeCard(CardEntity *card);
	void removeCards();
	virtual void take(int number);

private:
	std::vector <CardEntity *> cards;
	LinearLayout *cardsLayout;
	Deck *deck;
};

#endif // PLAYER_HPP
