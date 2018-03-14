//
// Created by agunner on 2/23/18.
//

#ifndef TEST_GAME_H
#define TEST_GAME_H

#include <SFML/Graphics.hpp>

class Game : private sf::NonCopyable {
public:
    Game();

    void run();

private:
    static const float PLAYER_SPEED;
    static const sf::Time TIME_PER_FRAME;

    //Window
    sf::RenderWindow mWindow;

    //Player
    sf::Texture mTexture;
    sf::Sprite mPlayer;

    //Statistics
    sf::Font mFont;
    sf::Text mStatisticsText;
    sf::Time mStatisticsUpdateTime;
    size_t mStatisticsNumFrames;

    bool mIsMovingUp;
    bool mIsMovingDown;
    bool mIsMovingRight;
    bool mIsMovingLeft;

    void processEvents();

    void update(sf::Time elapsedTime);

    void render();

    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

    void updateStatistics(sf::Time elapsedTime);

};

#endif //TEST_GAME_H
