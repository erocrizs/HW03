#include "StateSubclass.h"
#include <iostream>

GameState::GameState(StateManager* sm): sm(sm) {

}

void GameState::onActivate(std::string pass) {

}

void GameState::handleInput(const vec2i& mouse) {
    stage.handleInput(mouse);
}

void GameState::update(float dt) {
    stage.update(dt);
}

void GameState::render(sf::RenderWindow& window) {
    window.clear(sf::Color(214, 153, 255));
    stage.render(window);
}
