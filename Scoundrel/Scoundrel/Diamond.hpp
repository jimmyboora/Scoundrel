#pragma once

#include "card.hpp"


class Diamond : public Card
{
public:
	Diamond();
	Diamond(char v, char s, const sf::Texture* loadimage);

	char getvalue() override;
	char getsuit() override;

	void setValue(char newValue) override;
	void setSuit(char newSuit) override;

private:

};

inline Diamond::Diamond()
{
	value = '0';
	suit = '0';
}

inline Diamond::Diamond(char v, char s, const sf::Texture* loadimage)
{
	value = v;
	suit = s;
	this->setTexture(loadimage);
}

inline char Diamond::getvalue()
{
	return value;
}

inline char Diamond::getsuit()
{
	return suit;
}

inline void Diamond::setValue(char newValue)
{
	this->value = newValue;
}

inline void Diamond::setSuit(char newSuit)
{
	this->suit = newSuit;
}