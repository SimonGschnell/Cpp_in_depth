#include <iostream>

class Person{
    public:
    enum HairColor{
        red,blue,gree,yellow
    };

    Person(const HairColor& hc, std::string_view name, int age): m_hair_color{hc}, m_name{name}, m_age{age}{
        person_count++;
        inline_person_count++;
        std::cout << "person was created, count: " << inline_person_count << std::endl;
    }

    //? static data members in classes are not bound to objects but to the class itself
    //* therefore it is similar to a global variable that is qualified with the name of the class
    //! if the static data member is not const it has to be forward declared in the class
    static int person_count;
    //! if the static data member is an INTEGRAL constant it can be defined and initialized inside the class
    const static int person_count3{0};

    //! With the inline Keyword we can define and initialize the static data member inside the class
    //* this is the preffered way to initialize the static data member
    //?static data members can only be inline since in C++17
    inline static int inline_person_count{0};

    //? constexpr variables are implicitly inline in C++17
    static constexpr int person_count5{0};

    //! Best practice: make your static members inline or constexpr so they can be initialized inside the class definition.

    private:

    //? the definition of static data members can also be private and be implemented outside of the class
    static int person_count2;

    std::string m_name{};
    int m_age{};
    HairColor m_hair_color{};
};

//* the static data member can then be implemented directly underneath the class
//! This ensures that the initialization is performed only once, preventing multiple definitions.
int Person::person_count{0};
//? implementation of the private static data member 
int Person::person_count2{2};


int main(){

    Person p1{Person::blue, "Simon", 28};
    
    //? we can call static data members with an object but they are not bound to the object
    std::cout << "called from an object: " << p1.person_count << std::endl;

    std::cout << "called from the class: " << Person::person_count << std::endl;

    Person p2{Person::red, "Peter", 11};

    return 0;
}