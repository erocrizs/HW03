#include "BulletStage.h"

BulletStage::BulletStage(): base(vec2f(5, 5)) {
    borderBox.setFillColor(sf::Color(214, 153, 255));
    borderBox.setPosition(0, 0);
    borderBox.setSize(vec2f(600, 800));

    innerBox.setFillColor(sf::Color::Black);
    innerBox.setPosition(5, 5);
    innerBox.setSize(vec2f(590, 790));
}

void BulletStage::handleInput(const vec2i& mouse) {

}

void BulletStage::update(float dt) {

}

void BulletStage::render(sf::RenderWindow& window) const {
    window.draw(borderBox);
    window.draw(innerBox);
}
