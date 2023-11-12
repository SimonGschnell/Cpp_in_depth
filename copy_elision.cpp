#include <iostream>

//! COPY ELISION is a compiler optimization technique that allows the compiler to remove unnecessary copying of objects
//* that is why the copy constructor should generally not have any side effects as the constructor might get elided

class Person{
    private:
        std::string m_name{};
        int m_age{};
    public:
        Person(std::string_view name, int age): m_name{name}, m_age{age} {
            std::cout << "inside the initialization constructor" << std::endl;
        }
        //? copy constructor
        Person(const Person& other): m_name{other.m_name} , m_age{other.m_age}{
            std::cout << "inside the copy constructor" << std::endl;
        }
};

Person create_person(std::string_view name, int age){
    Person p{name,age}; // calls the init constructor
    return p; // calls the copy constructor //! but copy elision optimized the object instantiation
}


int main(){

    //? if the compiler wouldn't optimize the following line with copy elision, extra unnecessary constructor calls would have been made
    //* one initialization constructor to create the temporary object and a copy constructor to copy the temporary object
    Person simon{Person{"test",123}}; //! through the copy elision only the initalization constructor is called //the copy constructor is called is elided away

    Person p1 {create_person("simml",30)}; // should call the copy constructor again //! but copy elision optimized the instantiation of the object
    return 0;
}