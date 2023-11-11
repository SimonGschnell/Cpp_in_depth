#include <iostream>

class Person{
    private:
        std::string m_name{};
        int m_age{};
    public:
        Person(std::string_view name , int age): m_name{name}, m_age{age}{

        }
        const std::string_view get_m_name () const { return m_name;} 
        const int get_m_age () const { return m_age;} 
};

void printPerson(const Person& p){
    std::cout << "Person: name-"<< p.get_m_name() << " age-" << p.get_m_age() << std::endl;
}

//? returning temporary objects in functions
Person return_person1(){
    return Person{"Simon",26}; // returns temporary Person object
}

Person return_person2(){
    return {"Simon", 26}; // tries to implicitly convert to temporary Person object
}

int main(){

    Person simon { "Simon", 26 };
    //? When we only use a object once we can use a temporary/unnamed object instead (rvalue)
    printPerson(simon); 

    //* we have two valid ways to pass an temporary/unnamed object
    //! we can only use this where a rvalue is accepted, if the function would have a non-const reference, this would not work
    printPerson(Person{"Peter", 22}); // passing a temporary object of the class Person
    printPerson({"Peter", 22}); // or let the function implicitly use the initialization list for a new temporary Person

    return 0;
}