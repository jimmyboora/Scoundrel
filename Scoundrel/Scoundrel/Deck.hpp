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

class Deck
{
public:
	Deck();
	//~Deck();
	void shuffleDeck(); //Changed this function to shuffle the values of itself and not return a value
	vector<Card>& getcards();
	Card drawcard();
	void insertcard(Card card);
	void printDeck();
	void printShuffledDeck();


private:
	
	vector<Card> cardDeck;
	string suits[4];
	string rank[13];
	sf::Texture Dtexture[9];
	sf::Texture Htexture[9];
	sf::Texture Ctexture[13];
	sf::Texture Stexture[13];
};

Deck::Deck()
{
//	sf::Texture Dtexture[9] ={};
	Dtexture[0].loadFromFile("2_of_Diamonds.jpg");
	Dtexture[1].loadFromFile("3_of_Diamonds.jpg");
	Dtexture[2].loadFromFile("4_of_Diamonds.jpg");
	Dtexture[3].loadFromFile("5_of_Diamonds.jpg");
	Dtexture[4].loadFromFile("6_of_Diamonds.jpg");
	Dtexture[5].loadFromFile("7_of_Diamonds.jpg");
	Dtexture[6].loadFromFile("8_of_Diamonds.jpg");
	Dtexture[7].loadFromFile("9_of_Diamonds.jpg");
	Dtexture[8].loadFromFile("10_of_Diamonds.jpg");

//	sf::Texture Htexture[9] = {};
	Htexture[0].loadFromFile("2_of_Hearts.jpg");
	Htexture[1].loadFromFile("3_of_Hearts.jpg");
	Htexture[2].loadFromFile("4_of_Hearts.jpg");
	Htexture[3].loadFromFile("5_of_Hearts.jpg");
	Htexture[4].loadFromFile("6_of_Hearts.jpg");
	Htexture[5].loadFromFile("7_of_Hearts.jpg");
	Htexture[6].loadFromFile("8_of_Hearts.jpg");
	Htexture[7].loadFromFile("9_of_Hearts.jpg");
	Htexture[8].loadFromFile("10_of_Hearts.jpg");

//	sf::Texture Ctexture[13] = {};
	Ctexture[0].loadFromFile("2_of_Clubs.jpg");
	Ctexture[1].loadFromFile("3_of_Clubs.jpg");
	Ctexture[2].loadFromFile("4_of_Clubs.jpg");
	Ctexture[3].loadFromFile("5_of_Clubs.jpg");
	Ctexture[4].loadFromFile("6_of_Clubs.jpg");
	Ctexture[5].loadFromFile("7_of_Clubs.jpg");
	Ctexture[6].loadFromFile("8_of_Clubs.jpg");
	Ctexture[7].loadFromFile("9_of_Clubs.jpg");
	Ctexture[8].loadFromFile("10_of_Clubs.jpg");
	Ctexture[9].loadFromFile("J_of_Clubs.jpg");
	Ctexture[10].loadFromFile("Q_of_Clubs.jpg");
	Ctexture[11].loadFromFile("K_of_Clubs.jpg");
	Ctexture[12].loadFromFile("A_of_Clubs.jpg");

//	sf::Texture Stexture[13] = {};
	Stexture[0].loadFromFile("2_of_Spades.jpg");
	Stexture[1].loadFromFile("3_of_Spades.jpg");
	Stexture[2].loadFromFile("4_of_Spades.jpg");
	Stexture[3].loadFromFile("5_of_Spades.jpg");
	Stexture[4].loadFromFile("6_of_Spades.jpg");
	Stexture[5].loadFromFile("7_of_Spades.jpg");
	Stexture[6].loadFromFile("8_of_Spades.jpg");
	Stexture[7].loadFromFile("9_of_Spades.jpg");
	Stexture[8].loadFromFile("10_of_Spades.jpg");
	Stexture[9].loadFromFile("J_of_Spades.jpg");
	Stexture[10].loadFromFile("Q_of_Spades.jpg");
	Stexture[11].loadFromFile("K_of_Spades.jpg");
	Stexture[12].loadFromFile("A_of_Spades.jpg");

	suits[0] = "Diamonds";
	suits[1] = "Hearts";
	suits[2] = "Clubs";
	suits[3] = "Spades";


	rank[0] = "2";
	rank[1] = "3";
	rank[2] = "4";
	rank[3] = "5";
	rank[4] = "6";
	rank[5] = "7";
	rank[6] = "8";
	rank[7] = "9";
	rank[8] = "10";
	rank[9] = "Jack";
	rank[10] = "Queen";
	rank[11] = "King";
	rank[12] = "Ace";

	int i = 0, j = 0;
	for (i = 0; i < 4; i++)
	{
		if (i == 2 || i == 3)
		{
			for (j = 0; j < 13; j++)
			{
				if (i == 2)
				{
					cardDeck.push_back(Club(suits[i], rank[j], &Ctexture[j]));
				}
				if (i == 3)
				{
					cardDeck.push_back(Spade(suits[i], rank[j], &Ctexture[j]));

				}
			}
		}
		if (i == 0 || i == 1)
		{
			for (j = 0; j < 9; j++)
			{
				if (i == 0)
				{
					cardDeck.push_back(Diamond(suits[i], rank[j],&Dtexture[j]));
				}
				if (i == 1)
				{
					cardDeck.push_back(Heart(suits[i], rank[j], &Htexture[j]));
				}
			}
		}
	}
}

void Deck::shuffleDeck() //Changed this function to shuffle the values of itself and not return a value
{
	int newIndex = 0;
	vector<Card> shuffleDeck = cardDeck;
	for (int i = 0; i < cardDeck.size(); i++)
	{
		newIndex = rand() % shuffleDeck.size();
		std::swap(shuffleDeck[i], shuffleDeck[newIndex]);
	}
	cardDeck = shuffleDeck;
}

inline vector<Card> &Deck::getcards()
{
	return cardDeck;
}

inline Card Deck::drawcard()
{
	Card temp;
	temp = cardDeck.front();
	cardDeck.erase(cardDeck.begin());

	return temp;
}

inline void Deck::insertcard(Card card)
{
	cardDeck.push_back(card);
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
	//vector<Card> currentDeck = shuffleDeck();
	int i = 0;
	for (i = 0; i < cardDeck.size(); i++)
	{
		cardDeck[i].printCard();
	}
}