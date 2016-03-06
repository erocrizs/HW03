#ifndef STATESUBCLASS_H_INCLUDED
#define STATESUBCLASS_H_INCLUDED

#include "StateManager.h"

class SplashState: public State {
private:
    StateManager* sm;
    bool is_active;
public:
    SplashState(StateManager* sm);
    void handleInput(const vec2i& mouse) override;
    void update(float dt) override;
    void render(sf::RenderWindow& window) override;
};

#endif // STATESUBCLASS_H_INCLUDED
