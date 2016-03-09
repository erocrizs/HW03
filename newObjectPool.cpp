#include <iostream>
#include <assert.h>

template <class T>
class GenericPool
{
public:
    GenericPool<T>()
    {
        //the first one is available
        firstAvailable = &pool_[0];

        //Each sample points to the next
        for ( int i = 0; i < POOL_SIZE - 1; i++)
        {
            pool_[i].setNext(&pool_[i + 1]);
        }

        //The last one terminate the list
        pool_[POOL_SIZE - 1].setNext(nullptr);
    }

    //create a new T object
    //
    void create(float x1, float y1, float xVel1, float yVel1, int lifetime)
    {
        //Check that the pool is not full
        assert(firstAvailable != nullptr);

        // Remove it from the available list
        T* newT = firstAvailable;
        firstAvailable = newT->getNext();

        newT->init(x1, y1, xVel1, yVel1, lifetime);
    }

    void animate()
    {
        for(int i = 0; i < POOL_SIZE; i++)
        {
            if(pool_[i].animate())
            {
                //add to the front of the list
                pool_[i].setNext(firstAvailable);
                firstAvailable = &pool_[i];
                inUse_[i] = 0;
            }
            else inUse_[i] = 1;
        }
    }
private:
    static const int POOL_SIZE = 100;

    T* firstAvailable;
    T pool_[POOL_SIZE];
    bool inUse_[POOL_SIZE]; //to track the in-use state outside the objects
};

//Supposed structure/template for a class that will be using an object pool
class Sample
{
public:
    Sample()
    : framesLeft(0) //is not in use
    {}

    //Init function
    //is called when this object is to be used
    //Where the constructor parameters will be
    //such as Vector2 positions
    //lifetime is required for the object pool, you can put anything else besides that
    void init(float x1, float y1, float xVel1, float yVel1, int lifetime)
    {
        std::cout << " Creating new Sample" << std::endl;
        state.live.x = x1;
        state.live.y = y1;
        state.live.xVel = xVel1;
        state.live.yVel = yVel1;
        framesLeft = lifetime;
    }
    //Animate function
    //basically where you do the computations of an object
    //this will return a bool, which basically checks if it is in use or not
    bool animate() //originally void
    {
        if(!inUse()) return false;

        framesLeft--;
        state.live.x += state.live.xVel;
        state.live.y += state.live.yVel;

        std::cout << "X: " << state.live.x << "Y: " << state.live.y << " Frames Left: " << framesLeft << std::endl;
        return framesLeft == 0;
    }

    bool inUse() const {return framesLeft > 0;} //checks if there are still frame left, if there are, return true

    Sample* getNext() const {return state.next;} //get next Sample, like a node
    void setNext(Sample* next) {state.next = next;}//set the current Sample to the new Sample

private:
    int framesLeft;

    //basically, state will be composed of struct live, which contains the parameters specific to that class
    //and a pointer to the next instance of class
    union
    {
        //When in use
        struct
        {
            float x, y;
            float xVel, yVel;
        }live;

        Sample *next;
    } state;
};

int main()
{
    GenericPool<Sample> sp;

    //Create the samples
    sp.create(1, 2, 3, 4, 5);
    sp.create(1, 2, 3, 4, 5);
    sp.create(1, 2, 3, 4, 5);
    sp.create(1, 2, 3, 4, 5);
    sp.create(1, 2, 3, 4, 5);
    sp.create(1, 2, 3, 4, 5);

    while(true)
    {
        sp.animate();
    }

    return 0;
}
