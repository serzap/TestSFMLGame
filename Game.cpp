//
// Created by agunner on 2/23/18.
//

#include "Game.h"

const float Game::PLAYER_SPEED = 300.f;
const sf::Time Game::TIME_PER_FRAME = sf::seconds(1.f / 60.f);

Game::Game() : mWindow(sf::VideoMode(640, 480), "Test Game ", sf::Style::Close),
               mTexture(), mPlayer(),
               mFont(), mStatisticsText(), mStatisticsUpdateTime(), mStatisticsNumFrames(0),
               mIsMovingLeft(false), mIsMovingRight(false), mIsMovingDown(false), mIsMovingUp(false) {

    //PLayer
    mTexture.loadFromFile("../media/textures/Eagle.png");
    mPlayer.setTexture(mTexture);
    mPlayer.setPosition(300.f, 200.f);

    //Statistics
    mFont.loadFromFile("../media/fonts/Sansation.ttf");
    mStatisticsText.setFont(mFont);
    mStatisticsText.setPosition(5.f, 5.f);
    mStatisticsText.setCharacterSize(14);
}

void Game::run() {
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while (mWindow.isOpen()) {
        sf::Time elapsedTime = clock.restart();
        timeSinceLastUpdate += elapsedTime;
        while (timeSinceLastUpdate > TIME_PER_FRAME) {
            timeSinceLastUpdate -= TIME_PER_FRAME;
            processEvents();
            update(TIME_PER_FRAME);
        }
        updateStatistics(elapsedTime);
        render();
    }
}

void Game::processEvents() {
    sf::Event event{};
    while (mWindow.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::KeyPressed:
                handlePlayerInput(event.key.code, true);
                break;
            case sf::Event::KeyReleased:
                handlePlayerInput(event.key.code, false);
                break;
            case sf::Event::Closed:
                mWindow.close();
                break;
            default:
                break;
        }
    }
}

void Game::update(sf::Time elapsedTime) {
    sf::Vector2f movement(0.f, 0.f);
    if (mIsMovingUp) movement.y -= PLAYER_SPEED;
    if (mIsMovingDown) movement.y += PLAYER_SPEED;
    if (mIsMovingRight) movement.x += PLAYER_SPEED;
    if (mIsMovingLeft) movement.x -= PLAYER_SPEED;

    mPlayer.move(elapsedTime.asSeconds() * movement);
}

void Game::render() {
    mWindow.clear();
    mWindow.draw(mPlayer);
    mWindow.draw(mStatisticsText);
    //End the current frame and display its contents on screen
    mWindow.display();
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {
    if (key == sf::Keyboard::W)
        mIsMovingUp = isPressed;
    else if (key == sf::Keyboard::S)
        mIsMovingDown = isPressed;
    else if (key == sf::Keyboard::A)
        mIsMovingLeft = isPressed;
    else if (key == sf::Keyboard::D)
        mIsMovingRight = isPressed;
}

void Game::updateStatistics(sf::Time elapsedTime) {
    mStatisticsUpdateTime += elapsedTime;
    mStatisticsNumFrames++;

    if (mStatisticsUpdateTime >= sf::seconds(1.0f)) {
        mStatisticsText.setString(
                "Frames / Second = " + std::to_string(mStatisticsNumFrames) + "\n" +
                "Time / Update = " + std::to_string(mStatisticsUpdateTime.asMicroseconds() / mStatisticsNumFrames) +
                "ms");
        mStatisticsUpdateTime -= sf::seconds(1.0f);
        mStatisticsNumFrames = 0;
    }
}

