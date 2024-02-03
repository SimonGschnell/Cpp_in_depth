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
    //? pure virtual functions can also have a body definition, but the class still remains abstract and the body definition has to be defined outside of the class
        virtual void print() = 0;
    //? any class with pure virtual functions should also have a virtual destructor
    //* because every class that is meant to be inherited from should have a virtual destructor, and abstract classes are specifically meant to be inherited
        virtual ~Base() = default;
};

void Base::print(){
    std::cout << "Base Print" << std::endl;
}


//! any derived class that doesn't define the body for a pure virtual function will be considered as abstract as well
class Derived : public Base{
    public:
        //? we define the body for the pure virtual function, which makes the class a concrete class
        void printSelf() override {
            std::cout << "Derived" << std::endl;
        }

        //? pure virtual functions can have a defined body in case a derived class decides that the Base version of the pure virtual function is enough
        void print() override { 
            //? so that the derived class can reuse the body definition of the pure virtual function with the scope resolution operator of the base class
            Base::print();
        }
};

//? pure virtual functions are mainly used for Interface Classes
//* interface classes have no member variables and only have pure virtual functions that have to be refefined by the derived classes that inherit the interface class
//~ Interface Classes are often named beginning with an I
class IErrorLog{
    public:
        virtual bool openLog(std::string_view fileName)=0;
        virtual bool closeLog()=0;
        virtual bool writeError(std::string_view errorMessage)=0;

        virtual ~IErrorLog(){}
};

int main(){

    //? abstract classes cannot be instantiated
    //Base b{}; //! compiler error: object of abstract class "Base" is not allowed
    Derived d{};
    Base& b{d};
    b.printSelf();  // prints Derived
    b.print();      // prints Base, because Derived::print() calls Base::print() that has a defined body

    return 0;
}