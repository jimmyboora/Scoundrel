#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>

using std::string;

class ScreenButton : public sf::RectangleShape {
public:
	ScreenButton(const sf::Texture& newTexture);

	// No copy constructor

	~ScreenButton();

	sf::Sprite& getSprite();

	void activate();
	void deactivate();

	bool checkPressed() { return this->isPressed; };

	bool updateScreenButton(sf::RenderWindow& theWindow);
private:
	sf::Sprite mSprite;
	bool isPressed;
	bool isActive;
};

ScreenButton::ScreenButton(const sf::Texture& newTexture) : mSprite(newTexture), isPressed(false), isActive(false) {
	// Using initializer list
}

ScreenButton::~ScreenButton() {
	// Everything on the call stack so no need to specifically delete anything
}

sf::Sprite& ScreenButton::getSprite() {
	return this->mSprite;
}

void ScreenButton::activate() {
	this->isActive = true;
}


void ScreenButton::deactivate() {
	this->isActive = false;
}


bool ScreenButton::updateScreenButton(sf::RenderWindow& theWindow) {
	bool value = false;
	if (this->isActive) {
		sf::Vector2f mousePosition = theWindow.mapPixelToCoords(sf::Mouse::getPosition(theWindow));

		if (this->mSprite.getGlobalBounds().contains(mousePosition)) {
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
				this->isPressed = true;
				//std::cout << "BUTTON IS PRESSED" << std::endl;
				value = true;
			}
			else {
				this->isPressed = false;
				//std::cout << "BUTTON IS NOT PRESSED" << std::endl;
				value = false;
			}
		}
		else {
			this->isPressed = false;
			//std::cout << "MOUSE IS OUTSIDE OF BUTTON BOUNDS" << std::endl;
			value = false;
		}
	}

	theWindow.draw(this->mSprite);
	return value;
}