#include <iostream>
#include <string>
#include <string_view>

//? Inheritance allows us to reuse classes by having other classes inherit their members.

class Person{
    private:
        int m_age{};
        std::string m_name{};
    //? C++ has a third access specifier that is specifically used for inheritance
    //~ the protected access specifier, gives access to member functions, friend functions and derived classes
    protected: 
        int m_id{};
    public:
        Person(std::string_view name, int age): m_age{age}, m_name{name}{
            std::cout << "Person Constructor" << std::endl;
        }

        std::string_view getName(){
            return m_name;
        }

        int getAge(){
            return m_age;
        }

        friend std::ostream& operator<< (std::ostream& out , const Person& p){
            out << "{Person- Name:" << p.m_name << ", Age: "<< p.m_age << "}";
            return out;
        }

};

//? semicolon is used to inherit other classes
//? this case is a public inheritance because the Person class was inherited with the public accessor
//! when inheriting from a parent class, a child class cannot access the parent class private data members, getter and setter methods have to be used for this
//! because private data members can only be accessed by member functions of the same class or friends
class BaseBallPlayer: public Person{
    private:
    int m_homeruns{};
    double m_battingAverage{};
    public:
    //? we can call the constructor of the parent class in the member initialization list of the derrived class
    //? no matter where the call to the parent constructor is placed, it will always be called first
    BaseBallPlayer(std::string_view name, int age, int homeruns, double battingAverage): Person{name,age}, m_homeruns{homeruns}, m_battingAverage{battingAverage}{
        std::cout << "BaseBallPlayer Constructor" << std::endl;
        m_id = 55; //? protected data members from the parent class can be accessed directly by derrived classes
        //m_name = "Simon"; // private data members from the parent class can not be accessed by the derrived class //! compiler error: m_name is inaccessible
    }
    
    int getHomeruns(){
        return m_homeruns;
    }
    double getBattingAverage(){
        return m_battingAverage;
    }
    
};

int main(){
    //? when instantiating a class that is derrived from another class, all the constructors of the higher classes are called first until the constructor of the derrived class is called 
    BaseBallPlayer p1{"Simon", 26, 10, 1.5};
    std::cout << "BaseBallPlayer name: " << p1.getName() << std::endl;
    std::cout << "BaseBallPlayer age: " << p1.getAge() << std::endl;
    std::cout << "BaseBallPlayer batitngAverage: " << p1.getBattingAverage() << std::endl;
    std::cout << "BaseBallPlayer homeruns: " << p1.getHomeruns() << std::endl;

    return 0;
}