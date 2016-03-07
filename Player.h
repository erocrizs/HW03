#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "Entity.h"

class BulletStage;
class Player: public Entity {
private:
    BulletStage* stage;
    sf::CircleShape hitbox;
    sf::RectangleShape showbox;
    vec2f position, dimension, direction;
    float speed;
public:
    Player(BulletStage* stage);
    void update(float dt) override;
    void draw(sf::RenderWindow& window) const override;
};

#endif // PLAYER_H_INCLUDED
