//
// Created by agunner on 2/23/18.
//

#ifndef TEST_GAME_H
#define TEST_GAME_H

#include <SFML/Graphics.hpp>

class Game {
public:
    Game();

    void run();

private:
    sf::RenderWindow mWindow;
    sf::Texture mTexture;
    sf::Sprite mPlayer;
    static const float PLAYER_SPEED;
    static const sf::Time TIME_PER_FRAME;
    bool mIsMovingUp;
    bool mIsMovingDown;
    bool mIsMovingRight;
    bool mIsMovingLeft;

    void processEvents();

    void update(sf::Time timePerFrame);

    void render();

    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

};


#endif //TEST_GAME_H
