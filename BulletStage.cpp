#include "BulletStage.h"
#include <cmath>
#include <iostream>

BulletStage::BulletStage(): dimension(vec2f(490, 690)), position(vec2f(5, 5) + dimension/2.0f), player(this) {
    innerBox.setFillColor(sf::Color::Black);
    innerBox.setSize(dimension);
    innerBox.setOrigin(dimension/2.0f);
    innerBox.setPosition(position);
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


vec2f BulletStage::clamp(const vec2f point, const vec2f dimension) const {
    vec2f boxDim = this->dimension;
    float top = position.y -(boxDim.y/2.0) + dimension.y/2.0;
    float bottom = position.y + (boxDim.y/2.0) - dimension.y/2.0;
    float left = position.x - (boxDim.x/2.0) + dimension.x/2.0;
    float right = position.x + (boxDim.x/2.0) - dimension.x/2.0;
    float trueX = std::min(right, std::max(left, point.x));
    float trueY = std::min(bottom, std::max(top, point.y));
    return vec2f(trueX, trueY);
}
