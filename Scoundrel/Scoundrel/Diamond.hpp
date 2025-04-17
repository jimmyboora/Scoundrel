#pragma once

#include "card.hpp"


class Diamond : public Card
{
public:
	Diamond();
	Diamond(string v, string s, const sf::Texture* loadimage);

	string getvalue() override;
	string getsuit() override;

	void setValue(const string& newValue) override;
	void setSuit(const string& newSuit) override;

private:

};

inline Diamond::Diamond()
{
	value = '0';
	suit = '0';
}

inline Diamond::Diamond(string v, string s, const sf::Texture* loadimage)
{
	value = v;
	suit = s;
	this->setTexture(loadimage);
}

inline string Diamond::getvalue()
{
	return value;
}

inline string Diamond::getsuit()
{
	return suit;
}

inline void Diamond::setValue(const string& newValue)
{
	this->value = newValue;
}

inline void Diamond::setSuit(const string& newSuit)
{
	this->suit = newSuit;
}