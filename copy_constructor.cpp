#include <iostream>

//! unlike the implicit default constructor which does nothing (and thus is rarely what we want), the implicit copy constructor does exactly what we want

class Person{
    private:
        std::string m_name{};
        int m_age{};
    public:
        //? initialization constructor and at the same time default constructor by using default parameters
        Person(std::string_view name="simon", int age=26): m_name{name}, m_age{age} {
            std::cout << "person ("<< m_name << ", " << m_age << ")" << std::endl;
        }
        //? copy constructor (implicitly defined otherwise like the default constructor)
        //* the task of a copy constructor is to copy all data members if the same class object is used to instantiate an object
        // access specifiers are per-class basis, which means we can directly access the private members of the passed object of the same class
        Person(const Person& other): m_name{other.m_name}, m_age{other.m_age} {
            //! the copy constructor should not have any side effects because the compiler will be able to optimize it then
            std::cout << "the copy constructor was used" << std::endl;
            std::cout << "person ("<< m_name << ", " << m_age << ")" << std::endl;
        } 

        //! we can explicitly use the default copy constructor
        // Person(const Person& person) = default;
        //! or we can say that no copies of a class can be made (by removing the copy constructor) with the delete keyword
        // Person(const Person& person) = delete;

        const std::string& getName() const { return m_name; }
};

//? the copy constructor is used when a class object is passed by value
void print_person(Person p){
    std::cout << "person name: " << p.getName() << std::endl;
}

//? the copy constructor is used when a class object is returned by value
Person create_person(std::string name, int age){
    //! this example does not work because of the Copy elision Optimization used by the compiler
    Person p{name,age};
    return p;
}

int main(){

    Person p1 {"John",22}; // initialization constructor
    Person p2 {}; // default constructor
    Person p3 {p2}; // copy constructor

    print_person(p3);
    Person p4{create_person("abc",33)};
    
    return 0;
}