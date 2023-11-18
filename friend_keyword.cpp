#include <iostream>

//? A friend function is a function that can access the private and protected members of a class 
//? as though it were a member of that class. 

class Person{
    public:
        Person(std::string_view name, int age):m_name{name}, m_age{age}{}

        //? friend declaration for non-member function full_access
        //* friend declarations are not inpacted by access specifiers
        friend void full_access(const Person& p);

        //? friend non-member functions can also be fully defined inside the class but still be a non-member function
        friend void full_access_inside_class(const Person& p){
             std::cout << "printing private data members of class Person:\n" << "name: " << p.m_name << "\nage: " << p.m_age << std::endl;
        }

        //? example when we prefer a friend function over a member function
        bool isEqualToMember(const Person& other) const;
        //* friend function used when the logic doesn't involve the own object
        friend bool isEqualToOther(const Person& other1, const Person& other2);

    private:
        std::string m_name{};
        int m_age{};
};

//? implementation of the non-member function that is a friend of the Person class
//* the non-member function now has full access to the private data members without being part of the class
void full_access(const Person& p){
    //! because full_access is not a member function, an explicit object of the Person class has to be passed to the function, to access the private data members
    std::cout << "printing private data members of class Person:\n" << "name: " << p.m_name << "\nage: " << p.m_age << std::endl;
}

bool Person::isEqualToMember(const Person& p) const{
    return p.m_name == m_name && p.m_age == m_age;
}

bool isEqualToOther(const Person& other1, const Person& other2){
    return other1.m_name == other2.m_name && other1.m_age == other2.m_age;
}

int main(){

    Person p1{"Simon", 26};
    Person p2{"Simon", 26};
    full_access(p1);

    //? accessing the friend non-member function that was fully defined inside the Person class without using the qulified name of the class
    //Person::full_access_inside_class(p1); //! compiler error: class "Person" has no member function "full_access_inside_class"
    full_access_inside_class(p1);

    std::cout << std::boolalpha;
    std::cout << "p1.isEqualToMember(p2) == " << p1.isEqualToMember(p2) << std::endl;
    std::cout << "isEqualToOther(p1,p2) == " << isEqualToOther(p1,p2) << std::endl;

    return 0;
}