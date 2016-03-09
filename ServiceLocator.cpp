#include <unordered_map>
#include <typeinfo>
#include <string>
#include <iostream>
using namespace std;
class AudioController{

	public:
	    virtual void playAudio(int soundID) = 0;
	    virtual void stopAudio(int soundID) = 0;
	    virtual void stopAllAudio() = 0;
	    virtual ~AudioController(){}
};

class ScreenAudio : public AudioController
{
public:
  virtual void playAudio(int soundID)
  {
    cout<< "Play" <<endl;
  }

  virtual void stopAudio(int soundID)
  {
     cout<< "Stop" <<endl;
  }

  virtual void stopAllAudio()
  {
     cout<< "Stop All" <<endl;
  }
};

class ServiceLocator{

	std::unordered_map<std::string, void*> types;

	public:
	template<typename T>
	T& get(){
	    //get the element from the map with key Base Class
		auto s = types[typeid(T).name()];
        cout<<"Get: "<< typeid(T).name() << endl;
        cout << "Casted: " << typeid( *static_cast<T*>(s)).name()<< endl;

        //return the derived class
		return *static_cast<T*>(s);
	}

	template <typename B, typename D>// B- Base Class D - Derived class
	void provide(D &d){
	    //is_base_of checks whether D is a derived class of B or the same class. If not then print out the message.
		static_assert(std::is_base_of<B,D>::value, "B not base/same class of/as D");
		// Debug code
        cout<<"Provide: "<< typeid(d).name() << endl;
        // Puts the service in the map with the base class as the key
		types[typeid(B).name()] = &d;

	}

};


int main ()
{
  ServiceLocator sl;
  ScreenAudio sa;
  //cout<< typeid(sa).name()<<endl;
  sl.provide<AudioController>(sa);
  sl.get<AudioController>();
  return 0;
}

