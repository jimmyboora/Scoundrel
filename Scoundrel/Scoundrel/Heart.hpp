#pragma once

#include "card.hpp"


class Heart : public Card
{
public:
	Heart();
	Heart(char v, char s, const sf::Texture* loadimage);

	char getvalue() override;
	char getsuit() override;

	void setValue(char newValue) override;
	void setSuit(char newSuit) override;

private:

};

inline Heart::Heart()
{
	value = '0';
	suit = '0';
}

inline Heart::Heart(char v, char s, const sf::Texture* loadimage)
{
	value = v;
	suit = s;
	this->setTexture(loadimage);
}

inline char Heart::getvalue()
{
	return value;
}

inline char Heart::getsuit()
{
	return suit;
}

inline void Heart::setValue(char newValue)
{
	this->value = newValue;
}

inline void Heart::setSuit(char newSuit)
{
	this->suit = newSuit;
}