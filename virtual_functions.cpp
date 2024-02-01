#include <iostream>
#include <string>
#include <string_view>

//? virtual functions are special types of member functions that resolve to the most-derived version of the function
//* virtual functions need the same signature and return type as the Base class version to match
class Base{
    public:
        //? we create virtual functions by placing the keyword "virtual" in front of the function
        virtual void print(){
            std::cout << "Base" << std::endl;
        }
};

class Derived: public Base{
    public:
        //? the keyword "override" indicates that this function overrides a virtual function of an inherited class
        //! if it doesn't find a virtual function that matches the function signature in an inherited class, the compiler will throw an exception
        void print() override {
            std::cout << "Derived" << std::endl;
        }
        
        //void print2() override {} //! compiler error: member function declared with 'override' does not override a base class member
};

class MoreDerived: public Derived{
    public:

        void print() override {
            std::cout << "More Derived" << std::endl;
        }
};

int main(){

    Derived d{};
    MoreDerived md{};

    Base& ref_b{d};
    ref_b.print();  //? this will print "Derived" because it is the most derived version object referenced to
    Base& ref_b2{md};
    ref_b2.print(); //? this will print "More Derived" because it is the most derived version of the object referenced to

    //! Virtual function resolution only works when a member function is called through a pointer or reference to a class type object.
    //* calling virtual member function directly non-references/pointers don't work because those objects were created by copying the part their class belongs to
    Base b{md}; //? copyies the Base part of the MoreDerived object to create a new Base object
    b.print();  //? this will print "Base" because only the Base part of the Derived object was copyied to create lvalue b
}