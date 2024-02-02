#include <iostream>
#include <string>
#include <string_view>

class A{
    public:
        virtual void virtualPrint(){ std::cout << "A" << std::endl; }
        void normalPrint(){ std::cout << "A" << std::endl; }
        virtual A& get(){ return *this; }
};

//! we can also mark classes as final to prevent other classes from inheriting the class marked with final
class B final: public A{
    //? override helps to prevent bugs, because the function specifically needs the same signature as the inherited virtual function otherwise an error is thrown
    //! "final" is used to prevent new derived classes from overriding a virtual function marked with final
    public:
        void virtualPrint() override final { std::cout << "B" << std::endl; }
        void normalPrint() { std::cout << "B" << std::endl; }
        //? override member function have an exception where the return type can be different from the inherited virtual function
        //! Covariant return types, are references or pointers of types that are present in the same inheritance hierarchy
        //* We can return B& instead of return type A& in the inherited virtual function
        B& get() override { return *this; }
};

//! compiler error: a final class cannot be used as a base class
//class C: public B{

    //! compiler error: cannot override final function B::printSelf
    //void printSelf() override { std::cout << "C" << std::endl; } 
//};

int main(){
    B b{};
    A& a{b};
    a.virtualPrint();
    a.normalPrint();
    //? a.get() calls the override version of the virtual function in B::get which returns a &B
    //! but because A::get() returns a A&, B& is getting upcasted to A& and prints "A" when calling the non virtual function A::normalPrint()
    a.get().normalPrint();
    a.get().virtualPrint();

    return 0;
}