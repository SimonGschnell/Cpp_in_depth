#include <iostream>

//! a constructor is used to intialize data members that are hidden from the outside
// data members of structs are default public which makes it an aggregate and thus no need for a constructor because the data members can be initialized from the outside directly
//? but classes have their data members private by default 

class Person{
    //? private data members 
    private:
        std::string m_name{};
        int m_age{};
    public:
        //? constructor is a special member function that is called when a object is instantiated to initialize the data members of a class
        //* but constructors can also be used to perform other setup functions
        //! the constructor can be called for const objects because it is called implicitly, otherwise non-const memeber functions are not usable for const objects
        Person(const std::string& name, int age){
            m_name = name;
            m_age = age;
        }

        const std::string& get_name() const {
            return m_name;
        }
};

int main(){

    //? calls the constructor, where "Simon" and 26 are passed as arguments to the constructor of the class to initialize the data members of a class
    Person simon {"Simon", 26};

    std::cout << simon.get_name() << std::endl;

    return 0;
}