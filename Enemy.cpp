#include "Enemy.h"
#include "BulletStage.h"
#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

Enemy::Enemy(BulletStage* stage):
    Entity(stage),
    shootGap(1/10.0),
    shootCount(0),
    //move(PlayerMove::getInstance()),
    shoot(EnemyShoot::getInstance(shootGap)),
    position(stage->getPosition()+vec2f(0, -200)),
    dimension(vec2f(20, 30)), speed(200)
{
    this->stage = stage;

    showbox.setSize(dimension);
    showbox.setOrigin(dimension/(float)2.0);
    showbox.setFillColor(sf::Color::Magenta);
}

void Enemy::update(float dt) {
    shootCount = std::min(shootGap, shootCount+dt);
    if(shootCount==shootGap)
    {
        shoot(stage, position);
        shootCount = 0;
    }

    //move(this, dt);
    position = this->stage->clamp(position, dimension);
    //hitbox.setPosition(position);
    showbox.setPosition(position);
}

void Enemy::draw(sf::RenderWindow& window) const {
    window.draw(showbox);
}
