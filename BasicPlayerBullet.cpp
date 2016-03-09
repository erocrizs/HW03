#include "BasicPlayerBullet.h"
#include "BulletStage.h"

BasicPlayerBullet::BasicPlayerBullet(BulletStage* stage, vec2f position, vec2f direction):
    PlayerBullet(stage),
    move(StraightMovement::getInstance()),
    position(position),
    dimension(vec2f(10, 20)),
    direction(direction),
    speed(600) {
    this->position = position;
    this->stage = stage;

    box.setSize(dimension);
    box.setOrigin(dimension/2.0f);
    box.setFillColor(sf::Color::Red);
}

void BasicPlayerBullet::update(float dt) {
    move(this, dt);
    box.setRotation(getRadians(direction));
    box.setPosition(position);
}

void BasicPlayerBullet::draw(sf::RenderWindow& window) const {
    window.draw(box);
}
