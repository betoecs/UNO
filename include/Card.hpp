#ifndef CARD_HPP
#define CARD_HPP

class Card
{
public:
    enum Color
    {
        Red,
        Blue,
        Green,
        Yellow
    };

    enum Symbol
    {
        GamePad,
        Apple,
        Github,
        Leaf,
        Brush,
        Paw,
        Star,
        Bird,
        Rocket,
        Heart
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
