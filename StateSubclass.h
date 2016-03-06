#ifndef STATESUBCLASS_H_INCLUDED
#define STATESUBCLASS_H_INCLUDED

#include "StateManager.h"

class SplashState: public State {
private:
    StateManager* sm;
    bool is_active;
    sf::Font titleFont;
    sf::Font subtitleFont;
    sf::Text titleText;
    sf::Text subtitleText;
    sf::Text highScore;
    sf::Text playText;
public:
    SplashState(StateManager* sm);
    void onActivate(std::string pass) override;
    void handleInput(const vec2i& mouse) override;
    void update(float dt) override;
    void render(sf::RenderWindow& window) override;
};

#endif // STATESUBCLASS_H_INCLUDED
