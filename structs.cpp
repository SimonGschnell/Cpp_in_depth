#include <iostream>

//? definition of a struct (user-defined type) 
struct Employee {
    int id{};   //* variables inside a struct are called data members
    int age{};  //* the curly brackets ensure that each data member is initialized with a start value
    double wage{};
};

struct ConstEmployee {
    int id{};   //* variables inside a struct are called data members
    int age{};  //* the curly brackets ensure that each data member is initialized with a start value
    double wage{};
};

int main(){

    Employee joe { }; //? object creation from a struct definition
    joe.age = 32; //* struct data members can be initialized using the member selection operator "." and the assignment operator
    Employee frank { 2,25,2350.50 }; //? we can use aggregate initialization on structs because they are aggregate types
    Employee peter { 3,22 }; //? all not declared values for data members will stay uninitialized
    const Employee hans { 4, 30, 10.3 }; //? we can also declare const structs which data members can not by modified
    constexpr Employee susie { 5, 10, 22.33 }; //? same for constexpr structs

    frank = {frank.id, 26, 2400 }; //* aggregate data member manipulation
    joe = frank; //? we can also structs of the same type to use as intialization value

    std::cout << joe.age << std::endl;
    std::cout << frank.wage << std::endl;
    std::cout << peter.wage << std::endl;
    //hans.age = 3; //! compiler error
    

    return 0;
}