
#pragma once
#include "Menu.hpp"
#include <string>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include "Deck.hpp"
#include "Card.hpp"

#define RED "\033[0;31m"
#define CYN "\033[0;36m"

using std::string;
using std::vector;


class Test
{
public:
	bool test_loss(sf::RenderWindow& window);
	bool test_win(sf::RenderWindow& window);
	bool test_lastenemy();
	void test_all(sf::RenderWindow& window);
	int test_shuffle();
	int test_diamond();
	int test_club();
	int test_heart();
	int test_spade();
	int test_player_option();
	int test_stats();
	// int test_button();

private:

};


inline bool Test::test_loss(sf::RenderWindow& window)
{

	Deck cardDeck1;
	cardDeck1.shuffleDeck();
	sf::Texture filler;
	sf::Sprite sfiller(filler);
	Menu start(filler, filler, filler, filler, filler, sfiller, sfiller, filler, filler,filler);
	start.getplayer().setHealth(0);
	start.setplaystate(3);
	start.rungame(window, cardDeck1);
	if (start.getlost())
	{
		std::cout << "PASS" << std::endl;
		return true;
	}

	return false;
}

inline bool Test::test_win(sf::RenderWindow& window)
{
	Deck cardDeck1;
	cardDeck1.shuffleDeck();
	sf::Texture filler;
	sf::Sprite sfiller(filler);
	Menu start(filler, filler, filler, filler, filler, sfiller, sfiller, filler, filler, filler);
	start.setplaystate(7);
	start.rungame(window, cardDeck1);
	if (start.getwin())
	{
		std::cout << "PASS" << std::endl;
		return true;
	}



	return false;
}

inline bool Test::test_lastenemy()
{
	Card test;
	Player player1;
	test.setValue("10");
	test.setSuit("Diamonds");
	player1.updatePlayer(test);

	test.setValue("6");
	test.setSuit("Spades");
	player1.updatePlayer(test);

	test.setValue("10");
	test.setSuit("Spades");
	player1.updatePlayer(test);

	if (player1.getHealth() == 10)
	{
		std::cout << "PASS" << std::endl;
		return true;
	}



	return false;
}


void Test::test_all(sf::RenderWindow& window)
{
	int success1 = 0, success2 = 0, success3 = 0, success4 = 0, success5 = 0, success6 = 0, success7 = 0, success8 = 0;
	success1 = test_shuffle();
	success2 = test_diamond();
	success3 = test_heart();
	success4 = test_club();
	success5 = test_spade();
	success6 = test_loss(window);
	success7 = test_win(window);
	success8 = test_lastenemy();

	std::cout << "TESTING SHUFFLE: " << std::endl;
	if (success1 == 1)
	{
		std::cout << CYN "PASSED" << std::endl;
	}
	else
	{
		std::cout << RED "FAILED" << std::endl;
	}
	std::cout << "TESTING DIAMOND: " << std::endl;
	if (success2 == 1)
	{
		std::cout << CYN "PASSED" << std::endl;
	}
	else
	{
		std::cout << RED "FAILED" << std::endl;
	}
	std::cout << "TESTING HEART: " << std::endl;
	if (success3 == 1)
	{
		std::cout << CYN "PASSED" << std::endl;
	}
	else
	{
		std::cout << RED "FAILED" << std::endl;
	}
	std::cout << "TESTING CLUB: " << std::endl;
	if (success4 == 1)
	{
		std::cout << CYN "PASSED" << std::endl;
	}
	else
	{
		std::cout << RED "FAILED" << std::endl;
	}
	std::cout << "TESTING SPADE: " << std::endl;
	if (success5 == 1)
	{
		std::cout << CYN "PASSED" << std::endl;
	}
	else
	{
		std::cout << RED "FAILED" << std::endl;
	}
  	std::cout << "TESTING LOSS: " << std::endl;
	if (success6 == 1)
	{
		std::cout << CYN "PASSED" << std::endl;
	}
	else
	{
		std::cout << RED "FAILED" << std::endl;
	}
	std::cout << "TESTING WIN: " << std::endl;
	if (success7 == 1)
	{
		std::cout << CYN "PASSED" << std::endl;
	}
	else
	{
		std::cout << RED "FAILED" << std::endl;
	}
  	std::cout << "TESTING STACKED WEAPON: " << std::endl;
	if (success8 == 1)
	{
		std::cout << CYN "PASSED" << std::endl;
	}
	else
	{
		std::cout << RED "FAILED" << std::endl;
	}

}

int Test::test_shuffle()
{
	Deck testDeck;
	testDeck.shuffleDeck();
	vector<Card> testVector = testDeck.getcards();
	int club_count = 0, spade_count = 0, heart_count = 0, diamond_count = 0, success = 0;
	for (int i = 0; i < testVector.size(); i++)
	{
		if (testVector[i].getsuit() == "Clubs")
		{
			club_count++;

		}
		else if (testVector[i].getsuit() == "Spades")
		{
			spade_count++;
		}
		else if (testVector[i].getsuit() == "Hearts")
		{
			heart_count++;
		}
		else if (testVector[i].getsuit() == "Diamonds")
		{
			diamond_count++;
		}
	}
	if (club_count == 13 && spade_count == 13 && heart_count == 9 && diamond_count == 9)
	{
		success = 1;
	}
	return success;
}

int Test::test_diamond()
{
	Player player1;
	int success = 0;
	Diamond test_diamond;
	test_diamond.setSuit("Diamonds");
	test_diamond.setValue("7");
	player1.updatePlayer(test_diamond);
	if (player1.getHealth() == 20)
	{
		success = 1;
	}
	return success;
}

int Test::test_club()
{
	Player player1;
	int success = 0;
	Club test_club;
	test_club.setSuit("Spades");
	test_club.setValue("King");
	player1.updatePlayer(test_club);
	if (player1.getHealth() == 7)
	{
		success = 1;
	}
	return success;
}

int Test::test_heart()
{
	Player player1;
	int success = 0;
	Heart test_heart;
	Club club_subtract;
	club_subtract.setSuit("Clubs");
	club_subtract.setValue("10"); // Initial health for player will be 20, 20 - 10 = 10 (New health)
	player1.updatePlayer(club_subtract);
	test_heart.setSuit("Hearts");
	test_heart.setValue("7"); // Adds 7 Health back into player
	player1.updatePlayer(test_heart);
	if (player1.getHealth() == 17)
	{
		success = 1;
	}
	return success;
}

int Test::test_spade()
{
	Player player1;
	int success = 0;
	Spade test_spade;
	test_spade.setSuit("Spades");
	test_spade.setValue("7");
	player1.updatePlayer(test_spade);
	if (player1.getHealth() == 13)
	{
		success = 1;
	}
	return success;
}

int Test::test_player_option()
{
	return 0;
}

int Test::test_stats()
{
	return 0;
}

