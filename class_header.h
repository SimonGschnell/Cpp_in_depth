#ifndef CLASS_HEADER_H
#define CLASS_HEADER_H
#include <string>
#include <string_view>
#include <iostream>

//! Normally header files should be named after the class

class Person{
    private:
        std::string m_name{};
        int m_age{};
    public:
        //* member functions inside a class are inline by default and excempt from the ONE DEFINION RULE
        Person(std::string_view name, int age);
        void print() const;
        const std::string& get_greeting() const;

        //? and always put the default argument of a function in the forward declaration
        Person& add_age(int value=1);
        Person& subtract_age(int value=1); 
        void set_name(std::string_view name){ m_name = name; }
        const std::string& get_name() const { return m_name; }
        void set_age(int age){ m_age = age; }
        int get_age() const { return m_age; }
};

//? member functions defined outside of the class AND INSIDE the header file will cause the ONE DEFINITION RULE to break code
//! these functions have to be set to inline explicitly
//* this approach is also used for header-only libraries, where only the header file has to be included to work with the source code
inline const std::string& Person::get_greeting() const{
    return "hello Mr. ";
}

#endif