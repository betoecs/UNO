#ifndef CARD_HPP
#define CARD_HPP

class Card
{
public:
    enum Color
    {
        Red		= 0,
        Blue	= 1,
        Green	= 2,
        Yellow	= 3
    };

    enum Symbol
    {
        GamePad	= 0,
        Apple	= 1,
        Github	= 2,
        Leaf	= 3,
        Brush	= 4,
        Paw		= 5,
        Star	= 6,
        Bird	= 7,
        Rocket	= 8,
        Heart	= 9,
		Skip	= 10,
		Reverse = 11,
		Take2	= 12 
    };

    enum Compatibility
    {
        None,
        One,
        Two
    };

	Card();

    bool isUsed() const;
    void setUsed(bool used);
    Color getColor() const;
    void setColor(Color color);
    Symbol getSymbol() const;
    void setSymbol(Symbol symbol);
    Compatibility getCompatibility(const Card &card) const;

private:
    bool used;
    Color color;
    Symbol symbol;
};

#endif // CARD_HPP
