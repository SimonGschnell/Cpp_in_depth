#include <iostream>
#include <string>
#include <string_view>
#include <memory>

//? casting a derived object to a base object is called upcasting and is implicit and safe
//? casting a base object to a derived object is called downcasting and is not implicit and unsafe
//! downcasting can be unsafe because a reference/pointer of a base class may not point to a derived object when performing downcasting
//* we can perform downcasting using dynamic_cast, which returns the derived object if successful
//* otherwise it returns a nullptr if the reference/pointer is not pointing to a derived object

class Base{
    private:
        int m_base {};
    public:
        virtual ~Base(){}
        Base(int value): m_base{value}{}
        int getBase(){ return m_base; }
};

class Derived : public Base{
    private:
        std::string m_derived {};
    public:
        Derived(int value, std::string_view name): Base{value}, m_derived{name}{}
        //? getDerived is a member function Derived and is tightly coupled with a data member of the class
        //* therefore it is not possible to make this function a virtual function because the Base class would not have the appropriate data member
        std::string_view getDerived(){ return m_derived; }
};

std::unique_ptr<Base> getObject(bool condition){
    if(condition){
        return std::make_unique<Derived>(5,"simon");
    }else{
        return std::make_unique<Base>(10);
    }
}

int main(){

    //? pointing to Derived object
    auto obj = getObject(true);

    //! Always ensure your dynamic casts actually succeed by checking for null pointer results
    //? if the dynamic_cast was successful and did not return a nullptr
    Derived* d {dynamic_cast<Derived*>(obj.get())};
    if(d){
        //* dynamically casts the returned Base* from the unique_ptr::get function to Derived*
        //* then calls Derived::getDerived if the downcast was successful
        std::cout << d->getDerived() << std::endl;
    }else{
        std::cout << "nullptr" << std::endl;
    }

    //? pointing to Base object
    obj = getObject(false);
    d = dynamic_cast<Derived*>(obj.get());
    if(d){
        std::cout << d->getDerived() << std::endl;
    }else{
        //* prints nullptr if the dynamic_cast was not able to cast Base* to Derived*
        std::cout << "nullptr" << std::endl;
    }    

    //? dynamic_cast can also be used with references, if downcasting is not possible and because references have no null value, an exception std::bad_cast will be thrown
    Derived der{5,"Peter"};
    Base test{1};
    Base& base{der};
    Base& base2{test};
    std::cout << dynamic_cast<Derived&>(base).getDerived() << std::endl;
    //std::cout << dynamic_cast<Derived&>(base2).getDerived() << std::endl; //! throws std::bad_cast
    
    return 0;
}