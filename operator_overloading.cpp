#include <iostream>

//? operators are implemented as funcitons in c++ 
//~ by using function overloading on the operator functions a custom version of the operator can be used
//* overloading a operator function is called operator overloading


//! some operators can not be overloaded:
//* conditional ?:
//* scope ::
//* member selector .
//* pointer member selector .*


//~ operators can only be overloaded if one of the parameters is a user-defined type
//* otherwise it would overload a operator for primitive types which is not allowed

//! operators can be overloaded through
//* friend functions
//* normal functions 
//* member functions

class Person {
    public:

        Person(int age, std::string_view name): m_age{age}, m_name{name} {}

        //~ adding a friend function to overload the operator+ to add 2 Person objects
        friend int operator+(const Person& p1,const Person& p2) ;

        //! when we have operands of different types we have to implement to overloaded functions because x+y is not equal to y+x when the type differ
        //* Person(22) + 3   !=   3 + Person(22)
        friend int operator+(const Person& p1, int i2 );
        //? second overloading with switched parameters
        friend int operator+(int i1, const Person& p2 );

        friend const std::string operator!(const Person& p1 );

    private:
        std::string m_name{};
        int m_age{};
};

//~ implementation for the friend function that overloads the operator
int operator+(const Person& p1,const Person& p2){
    //? we can access the private members of the user defined objects because we have used a friend function
    return p1.m_age + p2.m_age;
}

int operator+(const Person& p1, int i2){
    return p1.m_age + i2;
}

int operator+(int i1 ,const Person& p2){
    //? if the implementation for the counter part of the overloaded operator is lengthy
    //~ the operator can be redirected by calling
    //* p2 + i1   --- which calls the counter part overloaded operator
    return i1 + p2.m_age;
}

const std::string operator!(const Person& p1 ){
    using namespace std::string_literals;
    return p1.m_name + " " + std::to_string(p1.m_age);
}

int main (){

    Person p1 {22, "simon"};
    Person p2 {10, "peter"};
    std::cout << p1 + p2 << std::endl;
    //? both overloaded operator versions are needed to compile the program
    std::cout << p1 + 3 << std::endl;
    std::cout << 3 + p1 << std::endl;
    std::cout << !p1 << std::endl;
    return 0;
}