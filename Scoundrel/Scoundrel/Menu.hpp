#pragma once 

#include "ScreenButton.hpp"
#include "Deck.hpp"


class Menu
{
public:
	Menu(const sf::Texture& Start, const sf::Texture& Info, const sf::Texture& Exit) : start(Start), info(Info), exit(Exit){
		start.getSprite().setPosition(sf::Vector2f(1920 / 2 - 150, 200));
		start.activate();

		info.getSprite().setPosition(sf::Vector2f(1920 / 2 - 150, 500));
		info.activate();

		exit.getSprite().setPosition(sf::Vector2f(1920 / 2 - 150, 800));
		exit.activate();
	
	}

	int updatestate(sf::RenderWindow& theWindow, Deck maindeck);
	void rungame();
	void printrules(sf::RenderWindow& theWindow);


private:
	int state; //State 1 is rungame, 2 is Show instructions, and 3 is exit
	ScreenButton start;
	ScreenButton info;
	ScreenButton exit;
};


inline int Menu::updatestate(sf::RenderWindow& theWindow, Deck maindeck)
{
	if (state == 0)
	{
		if (start.updateScreenButton(theWindow))
		{
			//std::cout << "Entering Game" << std::endl;
			state = 1;

		}
		if (info.updateScreenButton(theWindow))
		{
			//std::cout << "Print Info" << std::endl;
			state = 2;
		}
		if (exit.updateScreenButton(theWindow))
		{
			//std::cout << "Exiting" << std::endl;
			state = 3;
		}
	}
	if (state == 1)
	{
		//Start Game
		std::vector<Card> Playdeck = maindeck.getcards(); //Test for printing random card, it works!
		
		Playdeck[0].setPosition(sf::Vector2f(800, 600));
		theWindow.draw(Playdeck[0]);
	}
	if (state == 2)
	{
		//Print instuctions
		printrules(theWindow);
	}
	if (state == 3)
	{
		//Returns variable to exit program
		return 1;
	}
	return 0;
}

inline void Menu::printrules(sf::RenderWindow& theWindow)
{
	sf::Font font("ARIAL.TTF");

	sf::Text text(font); // a font is required to make a text object

	// set the string to display
	text.setString("Welcome to Scoundrel!\n\n\nThe Rules of this game are as follows:\n\nHEARTS are health, DIAMONDS are weapons, and SPADES/CLUBS are enemies");

	// set the character size
	text.setCharacterSize(50); // in pixels, not points!

	// set the color
	text.setFillColor(sf::Color::Black);

	// set the text style
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);

	// inside the main loop, between window.clear() and window.display()
	theWindow.draw(text);
}
