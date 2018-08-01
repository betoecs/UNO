#include "TurnIndicator.hpp"
#include <LK/Text.hpp>

///////////////////////////////////////
TurnIndicator::TurnIndicator() : LinearLayout(30, LinearLayout::Vertical), playerCount(0), currentPlayer(-1)
{
}

///////////////////////////////////////
void TurnIndicator::addPlayer(const std::string &playerName)
{
    auto player = new Text(playerName, "riffic.otf", 40);
    player->setOutlineThickness(5);
    player->setColor(Color("#797a78"));
    addChild(player);
    playerCount++;
}

///////////////////////////////////////
void TurnIndicator::setCurrentPlayer(int playerIndex)
{
    auto prevPlayer = dynamic_cast <Text *>(getChildByIndex(currentPlayer));
    auto newPlayer = dynamic_cast <Text *>(getChildByIndex(playerIndex));
    currentPlayer = playerIndex;

    if (prevPlayer)
        prevPlayer->setColor(Color("#797a78"));

    if (newPlayer)
        newPlayer->setColor(Color("#69ec2c"));
}

///////////////////////////////////////
void TurnIndicator::changeTurn()
{
    if (currentPlayer + 1 >= playerCount)
        setCurrentPlayer(0);
    else
        setCurrentPlayer(currentPlayer + 1);
}
