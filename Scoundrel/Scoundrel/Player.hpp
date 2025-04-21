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
	int getWeapon();
	void setHealth(int newHealth);
	void setDamage(int newDamage);
	void setWeapon(int newWeapon);
	int convertCardType(Card currentCard);
	void updatePlayer(Card currentCard);

private:
	int initialHealth;
	int initialDamage;
	int initialWeapon;
	Card cardPlayed;
};

Player::Player()
{
	initialHealth = 20;
	initialDamage = 0;
	initialWeapon = 0;
	cardPlayed = Card();
}

int Player::getHealth()
{
	return initialHealth;
}

int Player::getDamage()
{
	return initialDamage;
}

int Player::getWeapon()
{
	return initialWeapon;
}

void Player::setHealth(int newHealth)
{
	initialHealth = newHealth;
}

void Player::setDamage(int newDamage)
{
	initialDamage = newDamage;
}

void Player::setWeapon(int newWeapon)
{
	initialWeapon = newWeapon;
}

int Player::convertCardType(Card currentCard)
{
	string cardSuit = currentCard.getsuit(); // getSuit() and getRank() are accidently swapped so here we are actually getting the card rank, "1", "2", "3","4" etc
	int cardValue = 0;
	if (cardSuit == "Ace")
	{
		cardValue = 1;
	}
	else if (cardSuit == "2")
	{
		cardValue = 2;
	}
	else if (cardSuit == "3")
	{
		cardValue = 3;
	}
	else if (cardSuit == "4")
	{
		cardValue = 4;
	}
	else if (cardSuit == "5")
	{
		cardValue = 5;
	}
	else if (cardSuit == "6")
	{
		cardValue = 6;
	}
	else if (cardSuit == "7")
	{
		cardValue = 7;
	}
	else if (cardSuit == "8")
	{
		cardValue = 8;
	}
	else if (cardSuit == "9")
	{
		cardValue = 9;
	}
	else if (cardSuit == "10")
	{
		cardValue = 10;
	}
	else if (cardSuit == "Jack")
	{
		cardValue = 11;
	}
	else if (cardSuit == "Queen")
	{
		cardValue = 12;
	}
	else if (cardSuit == "King")
	{
		cardValue = 13;
	}
	return cardValue;
}

void Player::updatePlayer(Card currentCard)
{
	string cardSuit = currentCard.getsuit(); // Note: Found that the suit and rank are swapped through debugging. i.e, cardRank is "Clubs", "Diamonds, etc. cardSuit is "1", "2", "King" etc
	string cardRank = currentCard.getvalue(); // I just swapped suit and rank in this function.
	string lastSuit = cardPlayed.getsuit();
	string lastRank = cardPlayed.getvalue();
	int cardValue = convertCardType(currentCard);
	int lastValue = convertCardType(cardPlayed);
	int playState = 0;
	if (cardRank == "Diamonds")
	{
		lastValue = cardValue;
		lastRank = "Diamonds";
		initialWeapon = cardValue;
		playState = 0;
	}
	else if (cardRank == "Clubs" || cardRank == "Spades")
	{
		initialDamage = cardValue;
		playState = 1;
	}
	else if (cardRank == "Hearts")
	{
		playState = 2;
	}
	if (playState == 0)
	{
		if (initialWeapon < initialDamage)
		{
			initialHealth -= (initialDamage - initialWeapon);
		}
		else
		{
			initialHealth -= 0;
		}
	}
	else if (playState == 1)
	{
		if (lastRank == "Diamonds")
		{
			initialHealth -= (initialDamage - initialWeapon);
		}
		else
		{
			initialHealth -= initialDamage;
		}
	}
	else if (playState == 2)
	{
		initialHealth += cardValue;
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