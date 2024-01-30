#include <iostream>
#include <string>
#include <string_view>

class Base{
    private:
        int private_value{};
    protected:
        void printValue() const { std::cout << private_value << std::endl; }
    public:
        int public_value{};
        Base(int value) : private_value(value){}
        void printHello() const { std::cout << "hello" << std::endl; }

};

class Derrived : public Base {
    private:
        //? we can also hide functionality, by making public data members private
        using Base::public_value;
    protected:
    public:
        Derrived(int value): Base{value}{}
        //? we can change the access specifier of a inherited member function with the "using" keyword and the scope resolution operator
        //! private member function from the parent class are inaccessible and their access level cannot be changed
        using Base::printValue;
        //using Base::private_value; //! compiler error: private_value is inaccessible

        //? we cal also mark whole data members as deleted, so that it cannot be accessed through the derived class
        void printHello() const = delete;
};

int main(){
    Derrived d{5};
    d.printValue();
    //d.printHello(); //! compiler error: printHello is a deleted function

    //? Event when hiding functionality in the derived class, the data members are still available in the base/parent class
    //* some tricks to use them anyways
    d.Base::printHello(); //? calling the base class inside the derived class directly
    static_cast<Base&>(d).printHello(); //? casting the derived class to the base class 
}