#include "BulletStage.h"
#include <iostream>

BulletStage::BulletStage(): base(vec2f(255, 355)),  height(700), width(500), player(this) {
    innerBox.setFillColor(sf::Color::Black);
    innerBox.setSize(vec2f(width-10, height-10));
    innerBox.setOrigin(base-vec2f(5, 5));
    innerBox.setPosition(base);
}

void BulletStage::handleInput(const vec2i& mouse) {

}

void BulletStage::update(float dt) {
    player.update(dt);
}

void BulletStage::render(sf::RenderWindow& window) const {
    window.draw(innerBox);
    player.draw(window);
}
