#ifndef TURN_INDICATOR_HPP
#define TURN_INDICATOR_HPP

#include <LK/LinearLayout.hpp>
using namespace lk;

class TurnIndicator : public LinearLayout
{
public:
    TurnIndicator();
    void addPlayer(const std::string &playerName);
    void setCurrentPlayer(int playerIndex);
    void changeTurn();

private:
    int playerCount;
    int currentPlayer;
};

#endif // TURN_INDICATOR_HPP
