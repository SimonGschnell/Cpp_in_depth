#include <iostream>


class Person{
    private:
        //? member initialization list values take precedence over default initialization
        std::string m_name{"test"};
        int m_age{};
        const int id; // these must be initialized
        const int& ref_int; // these must be initialized
    public:
        //? using a member initialization list for the constructor of a class
        //* the member initialization list begins with a : after the constructor parameters and then list each member to initialize
        //! the member initialization list will initialize the members in the order they are defined in the class 
        Person(std::string name, int age): m_name{name}, m_age{age}, id{1} , ref_int{id}
        {
            //? inside the constructor only assignments occur not initializations
            //* for const variables of references that won't work
            //m_name = name;
            //id = 1; //! error: must be modifiable lvalue
            //ref_int = id; //! error: must be modifiable lvalue
        }

        void print_members(){
            std::cout << m_name << m_age << std::endl;
        }
};

int main(){

    Person simon{"simon",22};
    simon.print_members();

    return 0;
}