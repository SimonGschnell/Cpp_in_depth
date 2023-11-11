#include <iostream>

class Person{
    private:
        std::string m_name{};
        int m_age{};
    public:
        //? the process of calling constructors in the member initalization list of constructor is called constructor chaining
        //? we create a delegate constructor by calling another constructor of the member intialization
        Person(int age): Person{"", age}{
            //! we cannot call other constructor in the constructor body 
            // Person{"", age}; //! this would just create a temporary object that will be discarded, no member would have been initialized
        }
        //* here we are delegating the constructor that would only receive the name to the complete constructor with a default value 0 for the age data member
        //! if a constructor delegates the initialization to another constructor, the constructor itself can not initialize data members
        Person(std::string_view name): Person{name, 0}{//, m_age{age} would throw an compiler error

        }
        Person(std::string_view name, int age) : m_name{name}, m_age{age}{
            std::cout << "Person(" << m_name << "," << age << ") created" << std::endl;
        }
};

//? alternative is to reduce constructors with default arguments
class Car{
    private:
        std::string m_model{};
        int m_cost{};
    public:
        //? using default parameters in the constructor, allows to call the constructor in different ways
        //* both Car("Ferrari") and Car("Ferrari", 100000) are valid 
        Car(std::string_view model, int cost=0): m_model(model) , m_cost(cost){ 
        //? the most important data members have to be the first parameters and the least important ones should be the right most parameters

        }
};

int main(){

    Person simon {"simon"}; // delegated to Person(string_view, age)
    Person peter {33}; // delegated to Person(string_view, age)
    Person simon2 {"simon", 33}; 

    Car car1("Ferrari"); // usage of default parameter in constructor
    Car car2("Ferrari",100000); 

    return 0;
}