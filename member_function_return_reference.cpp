#include <iostream>

//! returning by reference typically is only safe if the returned value is still in scope after the end of the calling function
//* therefore only static local variables/global variables or REFERENCE PARAMETERS were valid options to be returned as references 
//! we can assume that data members have the same lifetime as the object containing them. 
//! Therefore it is safe for a member function to return a data member by const lvalue reference since the data member is still in scope when the function returns 

class Person{
    public :
        //
        void set_name(std::string_view value){
            name = value;
        }
        //? GETTER returning value by const lvalue reference
        //! This avoids returning expensive copies!
        //* returned type should match the type of the data member
        const std::string& get_name() const {
        
            return name;
        }

        //! Do not return non-const references to private data members as it will make direct acess to the data member possible 
        std::string& raw_get_name(){
            return name;
        }

    private :
        //
        std::string name{};
        int age{};
};


int main(){
    Person simon{};
    simon.set_name("Simon");

    //? usage of the getter function get_name that returns a const reference to the data member name of the object 
    //* it is garanteed to be in scope as long as the object itself is in scope
    std::cout << "The name of the person is: " << simon.get_name() << std::endl;

    //! we were able to set the value through the raw get that returns a non-const reference
    simon.raw_get_name() = "hacked";
    std::cout << simon.get_name() << std::endl;

    return 0;
}