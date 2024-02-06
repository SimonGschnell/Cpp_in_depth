#include <iostream>
#include <string>
#include <string_view>

//? It is not trivial to implement the operator<< for inherited classes, because operator<< is implemented as a friend function
//* friend functions cannot be virtual

class Base {
    public:
        virtual ~Base() {}
        //? virtual function that is overridden by derived classes
        virtual void print(std::ostream& out) const {
            out << "Base";
        }
        friend std::ostream& operator<< (std::ostream& out , const Base& b){
            //? we outsource the printing to a virtual member function of the base class
            b.print(out);
            return out;
        }
        
};

class Derived : public Base{
    public:
        void print(std::ostream& out) const override {
            out << "Derived";
        }
        
};

int main(){

    Derived d{};
    Base& b{d};

    std::cout << b << std::endl;


    return 0;
}