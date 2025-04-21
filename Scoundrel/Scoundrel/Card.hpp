#pragma once
#include <string>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <SFML/Graphics.hpp>

using std::string;


class Card : public sf::RectangleShape
{
public:
	Card();
	Card(string v, string s) : sf::RectangleShape(sf::Vector2f(100.f, 150.f))
	{
		value = v;
		suit = s;
	}
	virtual void setcard(Card newcard);
	virtual string getvalue();
	virtual string getsuit();


	virtual void setValue(const string& newValue);
	virtual void setSuit(const string& newSuit);

	void printCard() const;

protected:
	string value;
	string suit;

};

inline Card::Card()
{
	this->setSize(sf::Vector2f(200.f, 300.f));
	value = "";
	suit = "";
}

inline void Card::setcard(Card newcard)
{
	this->setTexture(newcard.getTexture());
	value = newcard.getvalue();
	suit = newcard.getsuit();
}

inline string Card::getvalue()
{
	return value;
}

inline string Card::getsuit()
{
	return suit;
}

inline void Card::setValue(const string& newValue)
{
	value = newValue;
}

inline void Card::setSuit(const string& newSuit)
{
	suit = newSuit;
}

void Card::printCard() const
{

	std::cout << suit << " " << value << std::endl;
}