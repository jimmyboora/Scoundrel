
#include "diamond.hpp"
#include "ScreenButton.hpp"


int main()
{

    sf::RenderWindow window(sf::VideoMode({ 1920, 1080 }), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);



    sf::Texture bgTexture;
    bgTexture.loadFromFile("background.jpg");

    sf::Texture startButtonTexture; 
    startButtonTexture.loadFromFile("2_of_Diamonds.jpg");
    ScreenButton testButton(startButtonTexture);
    testButton.getSprite().setPosition(sf::Vector2f(300, 300));
    testButton.activate(); 


    // sf::Texture input;
    // input.loadFromFile("2_of_Diamonds.jpg");
    sf::Sprite bgSprite(bgTexture);
    // Diamond tester('A', 'S', &input);
    // tester.setPosition(sf::Vector2f(500, 0));
    // tester.setScale(sf::Vector2f(.5, .5));


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
        testButton.updateScreenButton(window);
        //window.draw(tester);
        window.display();
    }
}