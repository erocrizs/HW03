#ifndef MOVEBEHAVIOR_H_INCLUDED
#define MOVEBEHAVIOR_H_INCLUDED

class Entity;
class MoveBehavior {
private:
    Entity* ent;
public:
    MoveBehavior(Entity* ent): ent(ent) {}
    virtual void operator() (Entity& e) = 0;
};

#endif // MOVEBEHAVIOR_H_INCLUDED
