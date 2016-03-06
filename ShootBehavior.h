#ifndef SHOOTBEHAVIOR_H_INCLUDED
#define SHOOTBEHAVIOR_H_INCLUDED

class Entity;
class ShootBehavior {
private:
    BulletStage* stage;
public:
    ShootBehavior(BulletStage* stage): stage(stage) {}
    virtual void operator() (Entity& e) = 0;
};

#endif // SHOOTBEHAVIOR_H_INCLUDED
