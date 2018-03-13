//
// Created by agunner on 2/23/18.
//

#include "Game.h"

const float Game::PLAYER_SPEED = 300.f;
const sf::Time Game::TIME_PER_FRAME = sf::seconds(1.f/80.f);

Game::Game() : mWindow(sf::VideoMode(640, 480), "Test Game "),mTexture(), mPlayer() {
    if(!mTexture.loadFromFile("../media/textures/Eagle.png")){
        //Error
    }
    mPlayer.setTexture(mTexture);
    mPlayer.setPosition(100.f, 100.f);
    mWindow.setVerticalSyncEnabled(true);
}

void Game::run() {
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while (mWindow.isOpen()) {
        processEvents();
        timeSinceLastUpdate += clock.restart();
        while(timeSinceLastUpdate > TIME_PER_FRAME) {
            timeSinceLastUpdate -= TIME_PER_FRAME;
            processEvents();
            update(TIME_PER_FRAME);
        }
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

void Game::update(sf::Time timePerFrame) {
    sf::Vector2f movement(0.f, 0.f);
    if (mIsMovingUp) movement.y -= PLAYER_SPEED;
    if (mIsMovingDown) movement.y += PLAYER_SPEED;
    if (mIsMovingRight) movement.x += PLAYER_SPEED;
    if (mIsMovingLeft) movement.x -= PLAYER_SPEED;

    mPlayer.move(timePerFrame.asSeconds() * movement);
}

void Game::render() {
    mWindow.clear();
    mWindow.draw(mPlayer);
    //Draw
    mWindow.display();
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {
    if (key == sf::Keyboard::W) mIsMovingUp = isPressed;
    else if (key == sf::Keyboard::S) mIsMovingDown = isPressed;
    else if (key == sf::Keyboard::A) mIsMovingLeft = isPressed;
    else if (key == sf::Keyboard::D) mIsMovingRight = isPressed;
}

