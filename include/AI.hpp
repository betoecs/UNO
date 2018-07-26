#ifndef AI_HPP
#define AI_HPP

#include "Player.hpp"
#include "GameScene.hpp"

class AI : public Player
{
public:
	enum Command
	{
		GetCard,
		SetCard,
		None
	};

	AI(GameScene *scene);
	void think();
	void doCommand();
	void take(int number) override;
	Card::Color chooseColor() const;
	int getCardCount(Card::Color color) const;
	std::vector <CardEntity *> getCardsByColor(Card::Color color) const;

private:
	GameScene *scene;
	Command command;
	CardEntity *cardToSet;
};

#endif // AI_HPP
