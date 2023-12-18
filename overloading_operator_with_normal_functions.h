#ifndef PERSON_OVERLOADING_OPERATOR
#define PERSON_OVERLOADING_OPERATOR

#include <iostream>
#include <string>
#include <string_view>

class Person{
    public:
        Person(std::string_view name , int age): m_name{name}, m_age{age} {}
        int get_age(){ return m_age; }
    private:
        std::string m_name{};
        int m_age{};
};

//? if we have public access member functions that can be used for the implementation of the overloaded operator
//* we prefere normal functions over friend functions if we don't have to create extra functions just for using normal functions

//! we need to define the forward declaration of the overloaded operator inside the header file, so that other files not of its existence when using it
int operator+(Person p1 , Person p2);

#endif