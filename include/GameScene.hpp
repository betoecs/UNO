#ifndef GAME_SCENE_HPP
#define GAME_SCENE_HPP

#include "CardEntity.hpp"
#include "Deck.hpp"
#include "Player.hpp"

#include <SFML/Window/Event.hpp>
#include <LK/Scene.hpp>
using namespace lk;

class AI;

class GameScene : public Scene
{
public:
	void onCreate() override;
	void onClose(int scene) override;

	void onUpdate(float frameTime) override;
	Deck & getDeck();
	bool setCurrentCard(Card *card, Player *applicant);
	const Card * getCurrentCard() const;
	void onClick(const sf::Event &event);

private:
	Deck deck;
	CardEntity *currentCardEntity;
	CardEntity *deckCardEntity;
	Player *player;
	AI *ai;
	Player *currentPlayer;
};

#endif // GAME_SCENE_HPP
