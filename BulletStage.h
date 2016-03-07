#ifndef BULLETSTAGE_H_INCLUDED
#define BULLETSTAGE_H_INCLUDED

#include <vector>
#include <SFML/Graphics.hpp>
#include "Vector2Plus.h"
#include "Player.h"

class BulletStage {
private:
    sf::RectangleShape innerBox;
    vec2f base;
    int height, width;
    Player player;
public:
    BulletStage();
    void handleInput(const vec2i& mouse);
    void update(float dt);
    void render(sf::RenderWindow& window) const ;
    int getHeight() {return height;}
    int getWidth() {return width;}
    vec2f getBase() {return base;}
};

#endif // BULLETSTAGE_H_INCLUDED
