#ifndef COLOR_SELECTOR_ENTITY_HPP
#define COLOR_SELECTOR_ENTITY_HPP

#include "Card.hpp"
#include <LK/Entity.hpp>
using namespace lk;

class ColorSelectorEntity : public Entity
{
public:
	ColorSelectorEntity();
	Signal <Card::Color> onSelect;
	void onClick(Card::Color selectedColor);
};

#endif // COLOR_SELECTOR_ENTITY_HPP
