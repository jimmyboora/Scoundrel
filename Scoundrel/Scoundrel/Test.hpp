
#include <gtest/gtest.h>
#include "Menu.hpp"
#include "Deck.hpp"
#include "Player.hpp"
#include "ScreenButton.hpp"

class MenuTest : public ::testing::Test 
{

protected:
    MenuTest() : menu(startButtonTexture, infoButtonTexture, exitButtonTexture, blankTexture, runButtonTexture, lostScreenSprite, winScreenSprite) {
        maindeck.shuffleDeck();
    }

    Menu menu;
    Deck maindeck;
    Player player1;
    sf::Texture startButtonTexture, infoButtonTexture, exitButtonTexture, blankTexture, runButtonTexture;
    sf::Sprite lostScreenSprite, winScreenSprite;
};



TEST_F(MenuTest, InitialStateIsZero) 
{
    ASSERT_EQ(menu.getState(), 0);
}


TEST_F(MenuTest, StartButtonActivatesGame)
{
    menu.updatestate(theWindow, maindeck);
    ASSERT_EQ(menu.getState(), 1);
}

TEST_F(MenuTest, InfoButtonActivatesInstructions) 
{
    menu.updatestate(theWindow, maindeck);
    ASSERT_EQ(menu.getState(), 2);
}


TEST_F(MenuTest, ExitButtonExitsGame) 
{
    menu.updatestate(theWindow, maindeck);
    ASSERT_EQ(menu.getState(), 3);
}

TEST_F(MenuTest, CardDrawsOnRunGame) 
{
    menu.rungame(theWindow, maindeck);
    ASSERT_EQ(maindeck.getcards().size(), 4);
}


TEST_F(MenuTest, PlayerHealthDecreasesAfterCardSelection) 
{
    menu.rungame(theWindow, maindeck);
    int initialHealth = player1.getHealth();
    menu.updatestate(theWindow, maindeck);
    ASSERT_LT(player1.getHealth(), initialHealth);
}

TEST_F(MenuTest, LostStateTriggersAfterPlayerHealthReachesZero) 
{
    player1.setHealth(0);
    menu.rungame(theWindow, maindeck);
    ASSERT_EQ(menu.getState(), 3);
}


TEST_F(MenuTest, WinningStateTriggersAfterPlayerWins)
{
    player1.setHealth(20);
    menu.rungame(theWindow, maindeck);
    ASSERT_EQ(menu.getState(), 7);
}
