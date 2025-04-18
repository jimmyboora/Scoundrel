#pragma once 

#include "ScreenButton.hpp"
#include "Deck.hpp"


//Constant values for card positions
namespace CardPositions {

	inline const sf::Vector2f POSITION_1 = { ((1920 / 2) - 500) - 100, 200 };
	inline const sf::Vector2f POSITION_2 = { ((1920 / 2) - 160) - 100, 200 };
	inline const sf::Vector2f POSITION_3 = { ((1920 / 2) + 160) - 100, 200 };
	inline const sf::Vector2f POSITION_4 = { ((1920 / 2) + 500) - 100, 200 };
	inline const sf::Vector2f WEAPON = { (1920 / 2) - 100, 700 };
	inline const sf::Vector2f WEAPON_STACK = { (1920 / 2) - 50, 725 };
}

using namespace CardPositions; //NO STD BS for this

class Menu
{
public:
	Menu(const sf::Texture& Start, const sf::Texture& Info, const sf::Texture& Exit, const sf::Texture& Blank) : start(Start), info(Info), exit(Exit), pos1(Blank),pos2(Blank),pos3(Blank),pos4(Blank),weapon(Blank),weaponstack(Blank) {
		start.getSprite().setPosition(sf::Vector2f(1920 / 2 - 150, 200));
		start.activate();

		info.getSprite().setPosition(sf::Vector2f(1920 / 2 - 150, 500));
		info.activate();

		exit.getSprite().setPosition(sf::Vector2f(1920 / 2 - 150, 800));
		exit.activate();

		pos1.getSprite().setPosition(POSITION_1);
		pos2.getSprite().setPosition(POSITION_2);
		pos3.getSprite().setPosition(POSITION_3);
		pos4.getSprite().setPosition(POSITION_4);
		weapon.getSprite().setPosition(WEAPON);
		weaponstack.getSprite().setPosition(WEAPON_STACK);


		pos1.getSprite().scale(sf::Vector2f(200.f/pos1.getSprite().getTexture().getSize().x, 300.f / pos1.getSprite().getTexture().getSize().y));
		pos2.getSprite().scale(sf::Vector2f(200.f / pos1.getSprite().getTexture().getSize().x, 300.f / pos1.getSprite().getTexture().getSize().y));
		pos3.getSprite().scale(sf::Vector2f(200.f / pos1.getSprite().getTexture().getSize().x, 300.f / pos1.getSprite().getTexture().getSize().y));
		pos4.getSprite().scale(sf::Vector2f(200.f / pos1.getSprite().getTexture().getSize().x, 300.f / pos1.getSprite().getTexture().getSize().y));
		weapon.getSprite().scale(sf::Vector2f(200.f / pos1.getSprite().getTexture().getSize().x, 300.f / pos1.getSprite().getTexture().getSize().y));
		weaponstack.getSprite().scale(sf::Vector2f(200.f / pos1.getSprite().getTexture().getSize().x, 300.f / pos1.getSprite().getTexture().getSize().y));
	
		state = 0;
		playstate = -1;
		cardspicked = 0;
	}

	int updatestate(sf::RenderWindow& theWindow, Deck maindeck);
	void rungame(sf::RenderWindow& theWindow,std::vector<Card> *Playdeck);
	void printrules(sf::RenderWindow& theWindow);


private:
	int state; //State 1 is rungame, 2 is Show instructions, and 3 is exit
	int playstate; //See run game for states
	int cardspicked;
	Card card1;
	Card card2;
	Card card3; 
	Card card4;
	Card weaponcard;
	Card weaponstackcard;
	ScreenButton start;
	ScreenButton info;
	ScreenButton exit;
	ScreenButton pos1;
	ScreenButton pos2;
	ScreenButton pos3;
	ScreenButton pos4;
	ScreenButton weapon;
	ScreenButton weaponstack;
};


inline int Menu::updatestate(sf::RenderWindow& theWindow, Deck maindeck)
{
	if (state == 0)
	{
		if (start.updateScreenButton(theWindow))
		{
			//std::cout << "Entering Game" << std::endl;
			state = 1;
			start.deactivate();
			info.deactivate();
			exit.deactivate();
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
	if (state == 1 || state == 4) //State 1 is the first interation of menue used for click guard
	{
		//Start Game
		std::vector<Card> Playdeck = maindeck.getcards(); //Test for printing random card, it works!
		rungame(theWindow, &Playdeck);
		state = 4;
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

inline void Menu::rungame(sf::RenderWindow& theWindow, std::vector<Card>* Playdeck)
{
	std::vector<ScreenButton> Cardslots = { pos1, pos2, pos3, pos4, weapon, weaponstack };
	int count = 0;

	if (state == 1) // Ensure if you hold left click for too long it wont pick a card
	{
		while (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
		}
	}

	//Start state = 0
	//First phase draw 4
	//Run -> (State 0) or Select card -> (State 1)
	if (playstate == -1)
	{
		card1 = Playdeck->front();
		card1.setPosition(POSITION_1);
		Playdeck->erase(Playdeck->begin());

		card2 = Playdeck->front();
		card2.setPosition(POSITION_2);
		Playdeck->erase(Playdeck->begin());

		card3 = Playdeck->front();
		card3.setPosition(POSITION_3);
		Playdeck->erase(Playdeck->begin());

		card4 = Playdeck->front();
		card4.setPosition(POSITION_4);
		Playdeck->erase(Playdeck->begin());

		pos1.activate();
		pos2.activate();
		pos3.activate();
		pos4.activate();

		playstate = 1;
	}


	theWindow.draw(card1);
	theWindow.draw(card2);
	theWindow.draw(card3);
	theWindow.draw(card4);

	for (int i = 0; i < Cardslots.size(); i++) {
		Cardslots[i].updateScreenButton(theWindow); // Updates all card slots and their hidden buttons
	}




	//Action state = 1
	//Update values until three cards are clicked -> (State 2) or Die -> (Exit state)
	if (playstate == 1)
	{
		if (Cardslots[0].updateScreenButton(theWindow))
		{
			pos1.deactivate();
			cardspicked++;
			card1.setPosition(sf::Vector2f(10000, 0));

		}
		if (Cardslots[1].updateScreenButton(theWindow))
		{
			pos2.deactivate();
			cardspicked++;
			card2.setPosition(sf::Vector2f(10000, 0));
		}
		if (Cardslots[2].updateScreenButton(theWindow))
		{
			pos3.deactivate();
			cardspicked++;
			card3.setPosition(sf::Vector2f(10000, 0));
		}
		if (Cardslots[3].updateScreenButton(theWindow))
		{
			pos4.deactivate();
			cardspicked++;
			card4.setPosition(sf::Vector2f(10000, 0));
		}
		if (cardspicked == 3)
		{
			playstate = 2;
		}
	}
	//Mid State = 2
	//Draw 3 cards
	// Run -> (State 0) or Fight (State 1)


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
