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
    for(int i=0; i<player_bullet.size(); i++)
    {
        PlayerBullet* pb = player_bullet[i];
        pb->update(dt);
        vec2f pos = pb->getPosition();
        vec2f margin = pb->getDimension() * -2.0f;
        if(clamp(pos, margin)!=pos) {
            delete player_bullet[i];
            player_bullet.erase(player_bullet.begin()+i);
            i--;
        }
    }
}

void BulletStage::render(sf::RenderWindow& window) const {
    window.draw(innerBox);
    player.draw(window);
    for(PlayerBullet* pb: player_bullet)
        pb->draw(window);
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

void BulletStage::addPlayerBullet(PlayerBullet* pb) {
    player_bullet.push_back(pb);
}
