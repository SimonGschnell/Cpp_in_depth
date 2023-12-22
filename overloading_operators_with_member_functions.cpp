#include <iostream>
#include <string>
#include <string_view>


class Person{
public:
    Person(std::string_view name, int age): m_name{name}, m_age{age}{}

    //? we can also overload operators with member functions
    //~ when using member functions to overload operators the left operand becomes the implicit this object
    Person operator+ (int value);
    //! because member functions have the left operand as the implicit this object, we are not able to overload the output operator << with member functions
    //* therefore we have to use a friend function or a normal function to overload the >> or << operator because the left operand has to be an istream or ostream
    friend std::ostream& operator<< (std::ostream& out , const Person& person);
private:
    std::string m_name{};
    int m_age{};
};

std::ostream& operator<< (std::ostream& out , const Person& person){
    out << "Person: " << person.m_name << ", " << person.m_age;
    return out;
}

Person Person::operator+ (int value){
    //? and because we are using a member function we are able to directly access the data members of the implicit this object
    //* in this case, adding a Person with an integer returns a new Person with the same name that has the combination of numbers as age
    return Person{ m_name, m_age + value };
}
int main(){

    Person p1 {"simon" , 24};

    std::cout << p1 + 44 << std::endl;



}