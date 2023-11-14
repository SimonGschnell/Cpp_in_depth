#include "class_header.h"

//* When a member function is modified, only this implementation code file has to be recompiled
//* While when modifying member functions in the header file, EVERY CODE FILE that uses that header file has to be recompiled

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
