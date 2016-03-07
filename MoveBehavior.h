#ifndef MOVEBEHAVIOR_H_INCLUDED
#define MOVEBEHAVIOR_H_INCLUDED

class Entity;
class MoveBehavior {
public:
    virtual void operator() () = 0;
};

#endif // MOVEBEHAVIOR_H_INCLUDED
