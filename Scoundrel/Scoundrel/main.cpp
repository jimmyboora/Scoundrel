#include "Card.hpp"
#include "Deck.hpp"
#include "Diamond.hpp"
#include "Spade.hpp"
#include "Club.hpp"
#include "Heart.hpp"
#include "Menu.hpp"


int main()
{
    std::srand((unsigned int)std::time(nullptr));
    Deck cardDeck1;
    cardDeck1.printDeck();
    std::cout << "--------------------------------------------- Shuffling Deck ------------------------------------------------" << std::endl;
    cardDeck1.shuffleDeck();
    cardDeck1.printShuffledDeck();

    int exit = 0;
    sf::RenderWindow window(sf::VideoMode({ 1920, 1080 }), "Scoundrel");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    // Tester code for button
    sf::Texture startButtonTexture;
    sf::Texture infoButtonTexture;
    sf::Texture exitButtonTexture;
    sf::Texture cardslot;
    sf::Texture runbutton;

    startButtonTexture.loadFromFile("StartButton.png");
    infoButtonTexture.loadFromFile("info_button.png");
    exitButtonTexture.loadFromFile("Quit.png");
    cardslot.loadFromFile("Clear_Space.png");
    runbutton.loadFromFile("Run_Button.png");
    Menu runit(startButtonTexture, infoButtonTexture, exitButtonTexture, cardslot,runbutton);

 /*   startButtonTexture.loadFromFile("StartButton.png");
    ScreenButton startButton(startButtonTexture);
    startButton.getSprite().setPosition(sf::Vector2f(1920 / 2 - 150, 500));
    startButton.activate();*/



    sf::Texture bgTexture;
    bgTexture.loadFromFile("background.jpg");
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

    while (window.isOpen() && exit == 0)
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

        // Testing the button
        //startButton.updateScreenButton(window);

        exit = runit.updatestate(window, cardDeck1);
        window.display();
    }
}