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
        Person(std::string_view name, int age);
        void print() const;
        Person& add_age(int value);
        Person& subtract_age(int value); 
        void set_name(std::string_view name){ m_name = name; }
        const std::string& get_name() const { return m_name; }
        void set_age(int age){ m_age = age; }
        int get_age() const { return m_age; }
};

#endif