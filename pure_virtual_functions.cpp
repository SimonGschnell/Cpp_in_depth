#include <iostream>
#include <string>
#include <string_view>

//* pure virtual functions are used to ensure that a derived class will have the virtual function redefined 
//* if the derived class does not redefine the pure virtual function, it will be treated as a abstract class and cannot be instantiated and the compiler will throw an error when using it any other way
//? pure virtual functions have no body definition and acts as a placeholder that is meant to be redefined by a derived class
//! any class that contains a pure virtual function becomes an abstract base class that cannot be instantiated

class Base{
    public:
    //? for pure virtual functions, instead of defining the body for the function, we assign the function the value 0
    //~ only the value of virtual functions can be set to 0
        virtual void printSelf() = 0;
        //? any class with pure virtual functions should also have a virtual destructor
        ~Base(){
            std::cout << "Base deallocated" << std::endl;
        }
};


//! any derived class that doesn't define the body for a pure virtual function will be considered as abstract as well
class Derived : public Base{
    public:
        //? we define the body for the pure virtual function, which makes the class a concrete class
        void printSelf() override {
            std::cout << "Derived" << std::endl;
        }
};

int main(){

    //? abstract classes cannot be instantiated
    //Base b{}; //! compiler error: object of abstract class "Base" is not allowed
    Derived d{};
    Base& b{d};
    b.printSelf();

    return 0;
}