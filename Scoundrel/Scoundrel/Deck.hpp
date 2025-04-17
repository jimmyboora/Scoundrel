#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Card.hpp"

using std::vector;
using std::string;

class Deck
{
public:
	Deck();
	//~Deck();
	vector<Card> shuffleDeck();
	void printDeck();
	void printShuffledDeck();

private:
	
	vector<Card> cardDeck;
	string suits[4];
	string rank[13];
};

Deck::Deck()
{
	suits[0] = "Diamonds";
	suits[1] = "Hearts";
	suits[2] = "Clubs";
	suits[3] = "Spades";

	rank[0] = "Ace";
	rank[1] = "2";
	rank[2] = "3";
	rank[3] = "4";
	rank[4] = "5";
	rank[5] = "6";
	rank[6] = "7";
	rank[7] = "8";
	rank[8] = "9";
	rank[9] = "10";
	rank[10] = "Jack";
	rank[11] = "Queen";
	rank[12] = "King";

	int i = 0, j = 0;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 13; j++)
		{
			cardDeck.push_back(Card(suits[i], rank[j]));
		}
	}
}

vector<Card> Deck::shuffleDeck()
{
	int newIndex = 0;
	vector<Card> shuffleDeck = cardDeck;
	for (int i = 0; i < cardDeck.size(); i++)
	{
		newIndex = rand() % shuffleDeck.size();
		std::swap(shuffleDeck[i], shuffleDeck[newIndex]);
	}
	return shuffleDeck;
}

void Deck::printDeck()
{
	int i = 0;
	for (i = 0; i < cardDeck.size(); i++)
	{
		cardDeck[i].printCard();
	}
}

void Deck::printShuffledDeck()
{
	vector<Card> currentDeck = shuffleDeck();
	int i = 0;
	for (i = 0; i < currentDeck.size(); i++)
	{
		currentDeck[i].printCard();
	}
}