#include <iostream>
#include <string>
#include <sstream>

class Person{
    private:
        std::string name = "simon";// c++11 default value for name
    public: 
        Person(); // constructor
        ~Person(); // destructor
        std::string getName();
        void setName(std::string name);
};

std::string Person::getName(){return name;};
void Person::setName(std::string name){
    this->name = name;
}

Person::Person(){
    std::cout << "object of Person was created" << std::endl;
    this->name = "simon";
}

Person::~Person(){
    std::cout << "object of Person was destroyed" << std::endl;
}


int main(){
    {
        Person p1;
        std::cout << p1.getName() << std::endl;
    }
    std::stringstream ss;
    //? concatenate different types to create a string
    ss << "my age is: ";
    ss << 26;
    ss << " years";

    std::cout << ss.str() << std::endl;
    return 0;
}
