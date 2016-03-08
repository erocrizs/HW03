#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "Entity.h"
#include "PlayerMove.h"

class BulletStage;
class Player: public Entity {
    friend class MoveBehavior;
private:
    BulletStage* stage;
    PlayerMove move;
    sf::CircleShape hitbox;
    sf::RectangleShape showbox;
    vec2f position, dimension, direction;
    float speed;
public:
    Player(BulletStage* stage);
    void update(float dt) override;
    void draw(sf::RenderWindow& window) const override;
    float getSpeed() const {
        return speed;
    }
    vec2f getPosition() const {
        return position;
    }
    void setPosition(const vec2f position) {
        this->position = position;
    }
};

#endif // PLAYER_H_INCLUDED
