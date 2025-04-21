#pragma once

#include "Card.hpp"


class Club : public Card
{
public:
	Club();
	Club(string v, string s, const sf::Texture* loadimage);

	string getvalue() override;
	string getsuit() override;

	void setValue(const string& newValue) override;
	void setSuit(const string& newSuit) override;

private:

};

inline Club::Club()
{
	value = "0";
	suit = "0";
}

inline Club::Club(string v, string s, const sf::Texture* loadimage)
{
	value = v;
	suit = s;
	this->setSize(sf::Vector2f(200.f, 300.f));
	this->setTexture(loadimage);
}

inline string Club::getvalue()
{
	return value;
}

inline string Club::getsuit()
{
	return suit;
}

inline void Club::setValue(const string& newValue)
{
	this->value = newValue;
}

inline void Club::setSuit(const string& newSuit)
{
	this->suit = newSuit;
}