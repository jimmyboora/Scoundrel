#pragma once

#include "card.hpp"


class Spade : public Card
{
public:
	Spade();
	Spade(char v, char s, const sf::Texture* loadimage);

	char getvalue() override;
	char getsuit() override;

	void setValue(char newValue) override;
	void setSuit(char newSuit) override;

private:

};

inline Spade::Spade()
{
	value = '0';
	suit = '0';
}

inline Spade::Spade(char v, char s, const sf::Texture* loadimage)
{
	value = v;
	suit = s;
	this->setTexture(loadimage);
}

inline char Spade::getvalue()
{
	return value;
}

inline char Spade::getsuit()
{
	return suit;
}

inline void Spade::setValue(char newValue)
{
	this->value = newValue;
}

inline void Spade::setSuit(char newSuit)
{
	this->suit = newSuit;
}