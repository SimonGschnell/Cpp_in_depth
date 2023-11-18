#include <iostream>

//! ref qualifiers are generally not used because they are not very known and clutter function definitions
//* ref qualifiers are not used in the standard library either 
//? single & ref qualifiers could be handy to ensure returning references of lvalue data members

class Person{
    public:
        Person(std::string_view name, int age):m_name{name}, m_age{age}{}

        //? return data members by const reference
        //! creates dangling references when called on a rvalue Person object
        const int& get_age() const { return m_age; }

        //? this can be prevented by explicitly telling the function to only execute on lvalue/rvalue objects
        //* this is possible using ref qualifiers
        //? ref qualifiers can be used to overload a member function
        //? it is only possible to overload with ref qualifiers or with parameter count/type not both
        //! can not be combined with const at the end of the function header
        const std::string& get_name() & { return m_name; } //! ensures that it is called on a lvalue
        //const std::string& get_name() && { return m_name; } //! ensures that it is called on a rvalue
        
    private:
        std::string m_name{};
        int m_age{};
        
};

Person generate_rvalue_Person(std::string_view name, int age){
    Person p1{name,age};
    return p1;
}

int main(){

    Person p1{"Simon",26};
    const int& age1 = p1.get_age();

    //? stores the reference to a rvalue Person object
    const int& age2 = generate_rvalue_Person("Peter",22).get_age();
    //! reference goes dangling after expression

    std::cout << "returned const reference on lvalue: " << age1 << std::endl;
    //? using the dangling reference causes undefined behavior
    std::cout << "returned const reference on rvalue: " << age2 << std::endl;

    std::cout << "getting the name by lvalue: " << p1.get_name() << std::endl;
    //std::cout << "returned const reference on rvalue: " << generate_rvalue_Person("a",1).get_name() << std::endl; //! this will error now

    return 0;
}