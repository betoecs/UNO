#ifndef GAME_SCENE_HPP
#define GAME_SCENE_HPP

#include "Deck.hpp"
#include "CardEntity.hpp"
#include "Player.hpp"

#include <SFML/Window/Event.hpp>
#include <LK/Scene.hpp>
using namespace lk;

class GameScene : public Scene
{
public:
	void onCreate() override;
	void onClose(int scene) override;

	bool setCurrentCard(Card *card);
	const Card * getCurrentCard() const;
	void onClick(const sf::Event &event);

private:
	Deck deck;
	CardEntity *currentCardEntity;
	CardEntity *deckCardEntity;
	Player *player;
};

#endif // GAME_SCENE_HPP
