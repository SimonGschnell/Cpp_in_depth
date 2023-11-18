#include <iostream>

class Person{
    public:
    enum HairColor{
        red,blue,gree,yellow
    };

    Person(const HairColor& hc, std::string_view name, int age): m_hair_color{hc}, m_name{name}, m_age{age}{
        private_inline_person_count++;
        std::cout << "person was created, count: " << private_inline_person_count << std::endl;
    }

    //? like static data members, member functions can also be static and called through the qualified class name
    //! static member functions have no `this` pointer because they are bond to the class and not to an object
    //! static member function can also not access non-static data members because they are bond to objects of the class
    static int get_person_count(){
        //this->m_name; //! compiler error: 'this' may only be used inside non static member functions
        //std::cout << m_name << std::endl; //! compiler error
        return private_inline_person_count;
    }

    //? we can also forward declare static member functions
    static void set_person_count(int value);

    private:

    //! cannot be accessed in the main function because it is private 
    //* we could create a member function to access the private static data members but 
    //? we can create static member functions to access private static data members
    static inline int private_inline_person_count{0};

    std::string m_name{};
    int m_age{};
    HairColor m_hair_color{};
};

//? static member functions can also be implemented outside of the class definition like static data members
void Person::set_person_count(int value){ Person::private_inline_person_count =value;}


int main(){

    Person p1{Person::blue, "Simon", 28};
    
    //std::cout << Person::private_inline_person_count << std::endl; //! private static data member can't be used here
    //? but we can call static member functions that access private static data members
    std::cout << Person::get_person_count() << std::endl; 

    //! calling static member function through objects is not recommended
    p1.get_person_count();

    Person p2{Person::red, "Peter", 11};

    Person::set_person_count(44);
    std::cout << Person::get_person_count() << std::endl;

    return 0;
}