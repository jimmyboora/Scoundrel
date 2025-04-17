#pragma once
#include <string>
#include <SFML/Graphics.hpp>


class Card : public sf::RectangleShape
{
public:
	Card();

	Card(char v, char s) : sf::RectangleShape(sf::Vector2f(100.f, 150.f))
	{
		value = v;
		suit = s;
	}

	virtual char getvalue() = 0;
	virtual char getsuit() = 0;

	virtual void setValue(char newValue);
	virtual void setSuit(char newSuit);

protected:
	char value;
	char suit;

};

inline Card::Card()
{
	this->setSize(sf::Vector2f(200.f, 300.f));
	value = 0;
	suit = 0;
}

inline void Card::setValue(char newValue)
{
	value = newValue;
}

inline void Card::setSuit(char newSuit)
{
	suit = newSuit;
}