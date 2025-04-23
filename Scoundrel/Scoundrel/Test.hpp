
#pragma once
#include "Menu.hpp"


class Test
{
public:
	bool test_loss(sf::RenderWindow& window);
	bool test_win(sf::RenderWindow& window);
	bool test_lastenemy();




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
