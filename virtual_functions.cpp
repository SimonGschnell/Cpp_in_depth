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
        //! virtual functions shouldn't be called in constructors or destructors 
        //? CONSTRUCTORS: when creating a derived class object, the inherited parts are constructed first therefore 
        //? when calling the virtual function in the constructor of the base class, the derived class won't be constructed yet
        //? DESTRUCTORS: when a derived class object is destroyed, it will be destroyed starting from the most derived part until the most base part
        //? therefore, when calling a virtual function in the destructor of the base class, the derived parts will be already destroyed
        Base(){ std::cout << "calling virtual function print() in constructor: "; print(); }
        Base( const Base& base ){ std::cout << "calling virtual function print() in copy constructor: "; print(); }
        ~Base(){ std::cout << "calling virtual function print() in destructor: "; print(); }
        
};

class Derived: public Base{
    public:
        //? If a function is virtual, all matching overrides in derived classes are implicitly virtual.
        //? "override" indicates that this function overrides a virtual function of an inherited class
        //! if it doesn't find a virtual function that matches the function signature in an inherited class, the compiler will throw an exception
        void print() override {
            std::cout << "Derived" << std::endl;
        }
        
        //* member functions marked as override can not be normal functions they have to override a virtual function that got inherited
        //void print() const override {} //! compiler error: member function declared with 'override' does not override a base class member
        //void print2() override {} //! same error here
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
    //! if you don't want to call the most derived version of a virtual function, you can use the scope resolution operator
    ref_b2.Base::print(); //? this will print "Base" because it used the scope resolution operator on a Base& reference

    //! Virtual function resolution only works when a member function is called through a pointer or reference to a class type object.
    //* calling virtual member function directly non-references/pointers don't work because those objects were created by copying the part their class belongs to
    Base b{md}; //? copyies the Base part of the MoreDerived object to create a new Base object
    b.print();  //? this will print "Base" because only the Base part of the Derived object was copyied to create lvalue b
}