#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <functional>

//? An derived object is constructed out of multiple parts of the base classes
//? Object slicing occurs when part of the object is beeing cut off 

class Base{
    int m_value{};
    public:
        Base(int value): m_value{value}{}
        virtual ~Base(){};
        virtual std::string_view getName(){
            return "Base";
        }
        int getValue(){
            return m_value;
        }
};

class Derived : public Base{
    int m_val{};
    public:
        Derived(int value, int val): Base{value}, m_val{val}{}
        std::string_view getName() override { return "Derived"; }
        int getVal(){return m_val; }
};

int main(){

    Derived d{5,2};
    //? Base class Type Pointer or and References assigned to a derived object, point to the Base part of the derived object but the Derived part still exists
    //* and the derived part can then be accessed through the use of virtual functions and virtual tables
    Base& ref_b{d};
    Base* ptr_b{&d};
    std::cout << ref_b.getName() << std::endl;  // prints Derived
    std::cout << ptr_b->getName() << std::endl; // prints Derived
    //! But if we assign a derived object to an Base class type object, only the base portion of the derived object is copied, the derived part is not copied
    //* Event thought getName is a virtual function, the derived part was lost during the copy construction and only Base::getName is left
    Base b{d};
    std::cout << b.getName() << std::endl;      // prints Base


    //? A problem that often occurs when working with vectors that implement polymorphism, using the Base type for the collection
    //! now every object that is pushed to the vector loses its derived part because it is sliced off
    //* And std::vector cannot be created using references because elements of vectors must be assignable, whereas references cannot be reassigned
    std::vector<Base> collection;
    collection.push_back(b);
    collection.push_back(d);
    for(auto& element : collection) {
        std::cout << element.getName() << std::endl; // Prints Base twice
    }

    //? To avoid this problem, we could store pointers (which introduces nullptr) or std::reference_wrapper (which is a reassignable wrapper class on top of references) 
    std::reference_wrapper<Base> r_d {d};
    std::reference_wrapper<Base> r_b {b};
    //* type deduction
    std::vector collection_wrappers {r_d, r_b};
    for(const auto& ref : collection_wrappers){
        std::cout << ref.get().getName() << std::endl; // Prints Derived then Base
    }


    //! Another problem of object slicing are Frankenobjects
    Derived der1{55,55};
    Derived der2{11,11};
    Base& base{der1};   // Reference to derived object der1
    base = der2;        // calling the default operator= of Base with argument Derived der2 (the default operator= is not virtual)
    //? This results in copying the Base part of der2 to der1 and keeping the Derived part of der1 the same
    //? This is called a Frankenobject because the parts of the object are from different objects
    std::cout << "Frankenobject => Base portion: " << der1.getValue() << ", Derived portion: " << der1.getVal() << std::endl;

    return 0;
}