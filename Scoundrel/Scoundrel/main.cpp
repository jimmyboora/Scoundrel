#include "Card.hpp"
#include "Diamond.hpp"
#include "Spade.hpp"
#include "Club.hpp"
#include "Heart.hpp"


int main()
{

    sf::RenderWindow window(sf::VideoMode({ 2000, 1000 }), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);



    sf::Texture bgTexture;
    bgTexture.loadFromFile("background.jpg");

    sf::Texture input;
    input.loadFromFile("2_of_Diamonds.jpg");
    sf::Sprite bgSprite(bgTexture);
    Diamond tester('A', 'S', &input);
    tester.setPosition(sf::Vector2f(500, 0));
    tester.setScale(sf::Vector2f(.5, .5));


    bgSprite.setScale(sf::Vector2f(window.getSize().x / 100, window.getSize().y / 100));

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        window.draw(bgSprite);
        window.draw(tester);
        window.display();
    }
}