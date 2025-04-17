#include "Card.hpp"
#include "Deck.hpp"
#include "Diamond.hpp"
#include "Spade.hpp"
#include "Club.hpp"
#include "Heart.hpp"


int main()
{
    std::srand((unsigned int)std::time(nullptr));

    Deck cardDeck1;
    cardDeck1.printDeck();
    std::cout << "--------------------------------------------- Shuffling Deck ------------------------------------------------" << std::endl;
    cardDeck1.shuffleDeck();
    cardDeck1.printShuffledDeck();

    sf::RenderWindow window(sf::VideoMode({ 1920, 1080 }), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);



    sf::Texture bgTexture;
    bgTexture.loadFromFile("background.jpg");

    sf::Texture input;
    input.loadFromFile("2_of_Diamonds.jpg");

    sf::Sprite bgSprite(bgTexture); //Background Sprite

    //Testers for all positions
    //Diamond tester1('A', 'S', &input);
    //Diamond tester2('A', 'S', &input);
    //Diamond tester3('A', 'S', &input);
    //Diamond tester4('A', 'S', &input);
    //Diamond tester5('A', 'S', &input);
    //Diamond tester6('A', 'S', &input);

    sf::Vector2f Position1 = { ((1920 / 2) - 500) - 100, 200 };
    sf::Vector2f Position2 = { ((1920 / 2) - 160) - 100, 200 };
    sf::Vector2f Position3 = { ((1920 / 2) + 160) - 100, 200 };
    sf::Vector2f Position4 = { ((1920 / 2) + 500) - 100, 200 };
    sf::Vector2f UserCard = { (1920 / 2) - 100, 700 };
    sf::Vector2f UserStack = { (1920 / 2) - 50, 725 };

    //Set position for each item for test
    //tester1.setPosition(Position1);
    //tester2.setPosition(Position2);
    //tester3.setPosition(Position3);
    //tester4.setPosition(Position4);
    //tester5.setPosition(UserCard);
    //tester6.setPosition(UserStack);


    bgSprite.setScale(sf::Vector2f(window.getSize().x / 100, window.getSize().y / 100));

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        window.draw(bgSprite); //Draw background

 //     Drawing all tests
        //window.draw(tester1);
        //window.draw(tester2);
        //window.draw(tester3);
        //window.draw(tester4);
        //window.draw(tester5);
        //window.draw(tester6);

        window.display();
    }
}