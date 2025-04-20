#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Card.hpp"
#include "Club.hpp"
#include "Spade.hpp"
#include "Diamond.hpp"
#include "Heart.hpp"


using std::vector;
using std::string;

class Player
{
public:
	Player();
	//~Player();
	int getHealth();
	int getDamage();
	void setHealth(int newHealth);
	void setDamage(int newDamage);
	void updatePlayer(Card currentCard);

private:
	int initialHealth;
	int initialDamage;
};

Player::Player()
{
	initialHealth = 20;
	initialDamage = 0;
}

int Player::getHealth()
{
	return initialHealth;
}

int Player::getDamage()
{
	return initialDamage;
}

void Player::setHealth(int newHealth)
{
	initialHealth = newHealth;
}

void Player::setDamage(int newDamage)
{
	initialDamage = newDamage;
}

void Player::updatePlayer(Card currentCard)
{
	string cardSuit = currentCard.getsuit(); // Note: Found that the suit and rank are swapped through debugging. i.e, cardRank is "Clubs", "Diamonds, etc. cardSuit is "1", "2", "King" etc
	string cardRank = currentCard.getvalue(); // I just swapped suit and rank in this function. 

	if (cardRank == "Clubs" || cardRank == "Spades") // Clubs and Spades decrease health
	{
		if (cardSuit == "Ace")
		{
			initialHealth -= 1;
			initialDamage += 1;
		}
		else if (cardSuit == "2")
		{
			initialHealth -= 2;
			initialDamage += 2;
		}
		else if (cardSuit == "3")
		{
			initialHealth -= 3;
			initialDamage += 3;
		}
		else if (cardSuit == "4")
		{
			initialHealth -= 4;
			initialDamage += 4;
		}
		else if (cardSuit == "5")
		{
			initialHealth -= 5;
			initialDamage += 5;
		}
		else if (cardSuit == "6")
		{
			initialHealth -= 6;
			initialDamage += 6;
		}
		else if (cardSuit == "7")
		{
			initialHealth -= 7;
			initialDamage += 7;
		}
		else if (cardSuit == "8")
		{
			initialHealth -= 8;
			initialDamage += 8;
		}
		else if (cardSuit == "9")
		{
			initialHealth -= 9;
			initialDamage += 9;
		}
		else if (cardSuit == "10")
		{
			initialHealth -= 10;
			initialDamage += 10;
		}
		else if (cardSuit == "Jack")
		{
			initialHealth -= 11;
			initialDamage += 11;
		}
		else if (cardSuit == "Queen")
		{
			initialHealth -= 12;
			initialDamage += 12;
		}
		else if (cardSuit == "King")
		{
			initialHealth -= 13;
			initialDamage += 13;
		}
	}
	else if (currentCard.getvalue() == "Hearts") // Hearts add health (20 max health)
	{
		if (cardSuit == "Ace")
		{
			initialHealth += 1;
		}
		else if (cardSuit == "2")
		{
			initialHealth += 2;
		}
		else if (cardSuit == "3")
		{
			initialHealth += 3;
		}
		else if (cardSuit == "4")
		{
			initialHealth += 4;
		}
		else if (cardSuit == "5")
		{
			initialHealth += 5;
		}
		else if (cardSuit == "6")
		{
			initialHealth += 6;
		}
		else if (cardSuit == "7")
		{
			initialHealth += 7;
		}
		else if (cardSuit == "8")
		{
			initialHealth += 8;
		}
		else if (cardSuit == "9")
		{
			initialHealth += 9;
		}
		else if (cardSuit == "10")
		{
			initialHealth += 10;
		}
		else if (cardSuit == "Jack")
		{
			initialHealth += 11;
		}
		else if (cardSuit == "Queen")
		{
			initialHealth += 12;
		}
		else if (cardSuit == "King")
		{
			initialHealth += 13;
		}
	}
	else if (currentCard.getvalue() == "Diamonds") // Diamonds add attack
	{

	}
	if (initialHealth > 20) // If the health ever goes over 20 reset the health to 20
	{
		initialHealth = 20;
	}
	else if (initialHealth <= 0) // If the health drops to 0 or below the game is over, for now a simple print statement will do
	{
		std::cout << "You Lose!" << std::endl;
	}
	std::cout << "Current Health: " << initialHealth << std::endl;
}