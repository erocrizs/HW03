#ifndef BULLETSTAGE_H_INCLUDED
#define BULLETSTAGE_H_INCLUDED

#include <vector>
#include <SFML/Graphics.hpp>
#include "Vector2Plus.h"

class BulletStage {
private:
    sf::RectangleShape borderBox;
    sf::RectangleShape innerBox;
    vec2f base;
public:
    BulletStage();
    void handleInput(const vec2i& mouse);
    void update(float dt);
    void render(sf::RenderWindow& window) const ;
};

#endif // BULLETSTAGE_H_INCLUDED
