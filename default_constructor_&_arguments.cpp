#include <iostream>

class Person {
    private:
        std::string m_name{};
        int m_age{};
    public: 
        //? the empty constructor is called the default constructor
        Person(){
            std::cout << "default constructor" << std::endl;
        }
        //? The constructor can be overloaded and the parameters of the constructor can have default values
        //* but if all values have default values, the constructor can be seen as the default constructor
        Person(std::string name , int age = 100): m_name{name}, m_age{age} {
            std::cout << m_name << " " << m_age << std::endl;
        }
};

class Car{
    private:
        std::string model{};
        int price{};
    //? no constructor has been defined, a default constructor will be implicitly created
    //* mostly used for classes that don't have data members
};

class House{
    private:
        std::string m_address{};
        int m_price{};
    public:
    //? we can also tell the compiler to generate an implicit constructor in cases where it would not have been created
    //* now both House{} and House{string , int} are valid instantiations for the class
    House() = default;
    House(std::string address, int price): m_address{address}, m_price{price}{

    }
};

int main(){

    Person p1{}; // calls the default constructor
    Person p2; // calls the default constructor
    Person p3{"simml"}; // calls the overloaded constructor

    Car c1{}; // calls the implicitly created default constructor

    return 0;
}