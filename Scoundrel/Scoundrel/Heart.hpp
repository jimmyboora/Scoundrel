#pragma once

#include "Card.hpp"


class Heart : public Card
{
public:
	Heart();
	Heart(string v, string s, const sf::Texture* loadimage);

	string getvalue() override;
	string getsuit() override;

	void setValue(const string& newValue) override;
	void setSuit(const string& newSuit) override;

private:

};

inline Heart::Heart()
{
	value = '0';
	suit = '0';
}

inline Heart::Heart(string v, string s, const sf::Texture* loadimage)
{
	value = v;
	suit = s;
//	this->setSize(sf::Vector2f(200.f, 300.f));
	this->setTexture(loadimage);
}

inline string Heart::getvalue()
{
	return value;
}

inline string Heart::getsuit()
{
	return suit;
}

inline void Heart::setValue(const string& newValue)
{
	this->value = newValue;
}

inline void Heart::setSuit(const string& newSuit)
{
	this->suit = newSuit;
}