#ifndef GAME_SCENE_HPP
#define GAME_SCENE_HPP

#include "CardEntity.hpp"
#include "Deck.hpp"
#include "Player.hpp"
#include "ColorSelectorEntity.hpp"
#include "TurnIndicator.hpp"

#include <SFML/Window/Event.hpp>
#include <LK/Scene.hpp>
using namespace lk;

class AI;

class GameScene : public Scene
{
public:
	void onCreate() override;
	void onReopen() override;
	void onClose(int scene) override;

	void onUpdate(float frameTime) override;
	Deck & getDeck();
	bool setCurrentCard(Card *card, Player *applicant);
	const Card * getCurrentCard() const;
	void onClick(const sf::Event &event);
	void onSelectedColor(Card::Color color);

private:
	void takeInitialCard();

	Deck deck;
	CardEntity *currentCardEntity;
	CardEntity *deckCardEntity;
	Player *player;
	AI *ai;
	Player *currentPlayer;
	Player *nextPlayer;
	ColorSelectorEntity *colorSelector;
	TurnIndicator *turnIndicator;
};

#endif // GAME_SCENE_HPP
