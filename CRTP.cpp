#include <iostream>

//? CRTP - Curiously Recurring Template Pattern
//* acts as a interface to provide functionality that has to be implemented in the derrived class

//? CRTP is often used to achieve compile-time polymorphism, where the behavior is determined at compile-time rather than run-time

template <typename T>
class Base{
    public :
        void name() { static_cast<T*>(this)->impl();}
};

class D1: public Base<D1>{
    public:
        void impl() { std::cout << "D1" << std::endl; }
};

int main(){
    D1 d1{};
    d1.name();
}