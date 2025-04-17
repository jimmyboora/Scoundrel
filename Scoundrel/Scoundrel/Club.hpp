#pragma once

#include "card.hpp"


class Club : public Card
{
public:
	Club();
	Club(char v, char s, const sf::Texture* loadimage);

	char getvalue() override;
	char getsuit() override;

	void setValue(char newValue) override;
	void setSuit(char newSuit) override;

private:

};

inline Club::Club()
{
	value = '0';
	suit = '0';
}

inline Club::Club(char v, char s, const sf::Texture* loadimage)
{
	value = v;
	suit = s;
	this->setTexture(loadimage);
}

inline char Club::getvalue()
{
	return value;
}

inline char Club::getsuit()
{
	return suit;
}

inline void Club::setValue(char newValue)
{
	this->value = newValue;
}

inline void Club::setSuit(char newSuit)
{
	this->suit = newSuit;
}