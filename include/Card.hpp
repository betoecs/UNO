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

	Card(Color color, Symbol symbol);

    bool isUsed() const;
    Color getColor() const;
    Symbol getSymbol() const;
    void setUsed(bool used);
    Compatibility getCompatibility(const Card &card) const;

private:
    bool used;
    Color color;
    Symbol symbol;
};

#endif // CARD_HPP
