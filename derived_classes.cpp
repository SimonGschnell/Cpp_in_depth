#include <iostream>
#include <string>
#include <string_view>

class Base{
    protected:
        int m_value{};
    public:
        Base(int value): m_value{value}{}
        void baseFunction() const { std::cout << "Function defined in the base class" << std::endl; }
        void identify() const { std::cout << "I am a Base class" << std::endl; }
        void accessSpecifierFunction() const { std::cout << "I am public" << std::endl; }
        friend std::ostream& operator<< (std::ostream& out, const Base& b){
            out << "In Base " << b.m_value << "\n";
            return out;
        }
    private:

};

class Derived : public Base{
    protected:
    public:
        Derived(int value): Base{value}{}
        int getValue() const {
            return m_value;
        }
        void identify() const { 
            //? we can call the original function from the base class by accessing it through the scope resolution qualifier of the base class
            //! the scope resolution qualifier Base:: is needed, only calling identify() would call the function of the current class and cause a infinite recursion loop
            //! scope resolution qualifiers won't work with friend functions
            Base::identify();
            //* and we can add extra functionality to the original base class function
            std::cout << "I am a Derived class" << std::endl;
        }
        friend std::ostream& operator<< (std::ostream& out, const Derived& d){
            out << "In Derived " << d.getValue() << "\n";
            //? instead of using the scope resolution qualifier, which won't work in friend functions because they are not part of the class
            //? we convert/cast the derived class to a base class to call the operator<< on a Base object
            out << static_cast<Base>(d);
            return out;
        }
    private:
        //? redefined member functions in the derived class don't inherit the access specifier
        //! their access sepcifier can be changed when overriding 
        void accessSpecifierFunction() const { std::cout << "I am public" << std::endl; }
};

int main(){

    Derived der {5};
    Base bas {5};
    std::cout << "Derrived class has inherited protected value: " << der.getValue() << std::endl;
    //? When a member function is called with a derived class object, 
    //? it uses the most-derived version of the function that it can find walking up the inheritance chain
    bas.baseFunction();
    der.baseFunction();
    //* identify was also defined in the derived class and was therefore overridden
    bas.identify();
    der.identify();
    //* Derived class changed access specifier when overriding the member function
    bas.accessSpecifierFunction();
    //der.accessSpecifierFunction(); //! compiler error: function inaccessible because private

    std::cout << "\n";
    std::cout << bas << std::endl;
    std::cout << der << std::endl;
    return 0;
}