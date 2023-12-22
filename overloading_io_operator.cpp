#include <iostream>
#include <string>
#include <string_view>

class Person {
    public:
        Person(std::string_view name, int age):m_name{name} , m_age{age}{}

        //? we can overload the operator<< wich takes a ostream object (std::cout in our case) and our user-defined object 
        friend std::ostream& operator<< (std::ostream& out , const Person& p);
        //? we can also overload the operator>> to read an user-defined object from std::in
        friend std::istream& operator>> (std::istream& in , Person& p);
        Person& chain_age_addition(int added_age){
            m_age += added_age;
            return *this;
        }
    private:
        std::string m_name{};
        int m_age{};
};

std::ostream& operator<< (std::ostream& out, const Person& p){
    //? inside of the implementation of the overloaded operator we use the << operator on the ostream std::cout to print the data members of the user-defined object
    //* since this is the implementation of a friend function, we are able to use the private data members of the Person class directly
    out << "Person: " << p.m_name << ", " << p.m_age;
    return out;
}

std::istream& operator>> (std::istream& in, Person& p){
    //? inside the implementation of the overloaded input operator we simply read the values that we use for the data members 
    in >> p.m_name;
    in >> p.m_age;
    return in;
}

int main(){
    Person p1 {"simon", 44};
    p1.chain_age_addition(2).chain_age_addition(4);
    std::cout << p1 << std::endl;

    std::cout << "please enter name and age of person separated by a space or newline: " ;
    std::cin >> p1;
    std::cout << "The new Person: " << p1 << std::endl;

    return 0;
}