#include "class_header.h"

//! member functions outside of the class are not excempt of the ONE DEFINITION RULE
//? Therefore those functions are usually defined in a code file (where they are only defined once)

//? full definition of the Person constructor
Person::Person(std::string_view name, int age): m_name{name}, m_age{age}{}

//? full definition of the member functions add_age and subtract_age
Person& Person::add_age(int value){
    m_age += value;
    return *this;
}
Person& Person::subtract_age(int value){
    m_age -= value;
    return *this;
}

//* definition for the print member function
void Person::print() const {
    std::cout << "Person: name - " << m_name << " | age - " << m_age << std::endl;
}
