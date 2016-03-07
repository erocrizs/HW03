#ifndef SHOOTBEHAVIOR_H_INCLUDED
#define SHOOTBEHAVIOR_H_INCLUDED

class Entity;
class ShootBehavior {
public:
    virtual void operator() () = 0;
};

#endif // SHOOTBEHAVIOR_H_INCLUDED
