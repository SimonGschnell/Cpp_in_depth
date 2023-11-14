#include "class_header.h"

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
