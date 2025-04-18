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
	Menu(const sf::Texture& Start, const sf::Texture& Info, const sf::Texture& Exit, const sf::Texture& Blank, const sf::Texture& Runbutton) : start(Start), info(Info), exit(Exit), pos1(Blank),pos2(Blank),pos3(Blank),pos4(Blank),run(Runbutton),weaponstack(Blank) {
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
		run.getSprite().setPosition(sf::Vector2f ((1920 / 2)-95, 575));
		weaponstack.getSprite().setPosition(WEAPON_STACK);


		pos1.getSprite().scale(sf::Vector2f(200.f/pos1.getSprite().getTexture().getSize().x, 300.f / pos1.getSprite().getTexture().getSize().y));
		pos2.getSprite().scale(sf::Vector2f(200.f / pos1.getSprite().getTexture().getSize().x, 300.f / pos1.getSprite().getTexture().getSize().y));
		pos3.getSprite().scale(sf::Vector2f(200.f / pos1.getSprite().getTexture().getSize().x, 300.f / pos1.getSprite().getTexture().getSize().y));
		pos4.getSprite().scale(sf::Vector2f(200.f / pos1.getSprite().getTexture().getSize().x, 300.f / pos1.getSprite().getTexture().getSize().y));
		run.getSprite().scale(sf::Vector2f(200.f / pos1.getSprite().getTexture().getSize().x, 300.f / pos1.getSprite().getTexture().getSize().y));
		weaponstack.getSprite().scale(sf::Vector2f(200.f / pos1.getSprite().getTexture().getSize().x, 300.f / pos1.getSprite().getTexture().getSize().y));

		state = 0;
		playstate = -1;
		cardspicked = 0;
		showrun = true;
	}

	int updatestate(sf::RenderWindow& theWindow, Deck &maindeck);
	void rungame(sf::RenderWindow& theWindow,Deck &Playdeck);
	void printrules(sf::RenderWindow& theWindow);


private:
	int state; //State 1 is rungame, 2 is Show instructions, and 3 is exit
	int playstate; //See run game for states
	int cardspicked;
	bool showrun;
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
	ScreenButton run;
	ScreenButton weaponstack;
};


inline int Menu::updatestate(sf::RenderWindow& theWindow, Deck& maindeck)
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
			if (maindeck.getcards().size() < 2)
			{
				maindeck.drawcard();
				maindeck.regenerate();
				maindeck.shuffleDeck();
				maindeck.printShuffledDeck();
			}
			std::cout << "Starting Game";
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
	else if (state == 1 || state == 4) //State 1 is the first interation of menue used for click guard
	{
		//Start Game
		rungame(theWindow, maindeck);
		if (maindeck.getcards().size() > 1)
		{
			state = 4;
		}
	}
	else if (state == 2)
	{
		//Print instuctions
		printrules(theWindow);
	}
	else if (state == 3)
	{
		//Returns variable to exit program
		return 1;
	}
	return 0;
}

inline void Menu::rungame(sf::RenderWindow& theWindow, Deck &Playdeck)
{
	std::vector<ScreenButton> Cardslots = { pos1, pos2, pos3, pos4, run, weaponstack };
	int count = 0;
	

	if (state == 1) // Ensure if you hold left click for too long it wont pick a card
	{
		while (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
		}
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//Start state = 0
	//First phase draw 4
	//Run -> (State 0) or Select card -> (State 1)
	if (playstate == -1 && Playdeck.getcards().size() > 1)
	{
		card1 = Playdeck.drawcard();
		card1.setPosition(POSITION_1);

		card2 = Playdeck.drawcard();
		card2.setPosition(POSITION_2);

		card3 = Playdeck.drawcard();
		card3.setPosition(POSITION_3);

		card4 = Playdeck.drawcard();
		card4.setPosition(POSITION_4);

		pos1.activate();
		pos2.activate();
		pos3.activate();
		pos4.activate();

		playstate = 1;
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//Action state = 1
	//Update values until three cards are clicked -> (State 2) or Die -> (Exit state)
	if (playstate == 1)
	{
		if (showrun == true)
		{
			run.activate();
		}
		if (showrun == false)
		{
			run.deactivate();
		}
		if (run.updateScreenButton(theWindow)) //Draws new cards for run state
		{
			Playdeck.insertcard(card1);
			Playdeck.insertcard(card2);
			Playdeck.insertcard(card3);
			Playdeck.insertcard(card4);
			run.deactivate();
			showrun = false;
			playstate = -1;
		}
		if (Cardslots[0].updateScreenButton(theWindow))
		{
			pos1.deactivate();
			cardspicked++;
			card1.setPosition(sf::Vector2f(10000, 0));
			showrun = false;

		}
		if (Cardslots[1].updateScreenButton(theWindow))
		{
			pos2.deactivate();
			cardspicked++;
			card2.setPosition(sf::Vector2f(10000, 0));
			showrun = false;
		}
		if (Cardslots[2].updateScreenButton(theWindow))
		{
			pos3.deactivate();
			cardspicked++;
			card3.setPosition(sf::Vector2f(10000, 0));
			showrun = false;
		}
		if (Cardslots[3].updateScreenButton(theWindow))
		{
			pos4.deactivate();
			cardspicked++;
			card4.setPosition(sf::Vector2f(10000, 0));
			showrun = false;
		}
		if (cardspicked == 3 && Playdeck.getcards().size() > 1) // Kicks out of state once 3 cards are picked
		{
			playstate = 2;
			cardspicked = 0;
			showrun = true;
		}
		if (cardspicked == 4)
		{
			//Place winning screen here
			std::cout << "WINNER";
			cardspicked = 0;
			state = 0;
			playstate = -1;
			pos1.deactivate();
			pos2.deactivate();
			pos3.deactivate();
			pos4.deactivate();
			run.deactivate();
			start.activate();
			info.activate();
			exit.activate();

		}
	}


	////////////////////////////////////////////////////////////////////////////////////////////////////////////


	//Mid State = 2
	//Draw 3 cards
	// Run -> (State 0) or Fight (State 1)
	if (playstate == 2 && Playdeck.getcards().size() > 1)
	{
		std::cout << Playdeck.getcards().size() << std::endl;
		if (pos1.getactive() == false)
		{
			card1 = Playdeck.drawcard();
			card1.setPosition(POSITION_1);
			pos1.activate();
		}
		if (pos2.getactive() == false)
		{
			card2 = Playdeck.drawcard();
			card2.setPosition(POSITION_2);
			pos2.activate();
		}
		if (pos3.getactive() == false)
		{
			card3 = Playdeck.drawcard();
			card3.setPosition(POSITION_3);
			pos3.activate();
		}
		if (pos4.getactive() == false)
		{
			card4 = Playdeck.drawcard();
			card4.setPosition(POSITION_4);
			pos4.activate();
		}
		playstate = 1;
		if (playstate == 1) // Ensure if you hold left click for too long it wont pick a card
		{
			while (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			}
		}

	}

		////////////////////////////////////////////////////////////////////////////////////////////////////////////


		//for (int i = 0; i < Cardslots.size(); i++) {
		//	Cardslots[i].updateScreenButton(theWindow); // Updates all card slots and their hidden buttons
		//}
		theWindow.draw(card1);
		theWindow.draw(card2);
		theWindow.draw(card3);
		theWindow.draw(card4);
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
