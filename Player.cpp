#include "Player.h"
#include "BulletStage.h"
#include "PlayerMove.h"
#include <iostream>

Player::Player(BulletStage* stage): Entity(stage), move(PlayerMove::getInstance()), position(stage->getBase()+vec2f(0, 200)), dimension(vec2f(20, 30)), speed(300)
{
    hitbox.setRadius(3);
    hitbox.setOrigin(3, 3);
    hitbox.setFillColor(sf::Color::White);

    showbox.setSize(dimension);
    showbox.setOrigin(dimension/(float)2.0);
    showbox.setFillColor(sf::Color::Blue);
}

void Player::update(float dt) {
    move(this, dt);
    hitbox.setPosition(position);
    showbox.setPosition(position);
    std::cout << "Reality: " << position.x << ", " << position.y << std::endl;
}

void Player::draw(sf::RenderWindow& window) const {
    window.draw(showbox);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
        window.draw(hitbox);
}
