#pragma once

#include "card.hpp"


class Spade : public Card
{
public:
	Spade();
	Spade(string v, string s, const sf::Texture* loadimage);

	string getvalue() override;
	string getsuit() override;

	void setValue(const string& newValue) override;
	void setSuit(const string& newSuit) override;

private:

};

inline Spade::Spade()
{
	value = '0';
	suit = '0';
}

inline Spade::Spade(string v, string s, const sf::Texture* loadimage)
{
	value = v;
	suit = s;
	this->setTexture(loadimage);
}

inline string Spade::getvalue()
{
	return value;
}

inline string Spade::getsuit()
{
	return suit;
}

inline void Spade::setValue(const string& newValue)
{
	this->value = newValue;
}

inline void Spade::setSuit(const string& newSuit)
{
	this->suit = newSuit;
}