#include <iostream>
#include <string>

//! structs have the same capabilities as classes
struct Person {
  //? member variables are public by default in structs
  std::string name {};
  int age {};

  //? we can create member functions for structs
  void greeting_from_person(){
    std::cout << "Hello I am " << age << " years old and my name is " << name << std::endl;
  }

  //! member functions can be overloaded and differenciated over their const-ness
  //* which allows us to have the same member function both in a const and non-const version
  void greeting_from_person() const {
    std::cout << "Hello I am " << age << " years old and my name is " << name << std::endl;
  }

  //? we can create a const member function that will garantee that it doesn't modify member variables
  //* const member functions have the const keyword before the body starts
  //! best practice: if a member function does not modify the state of the object, it should be const 
  void print_name() const {
    std::cout << " Name : " << name << std::endl;
  }

  void increase_age_by_one(){
    ++age;
  }
};

//? we can pass structs as const references 
void do_something(const Person& person){
  // person.greeting_from_person(); //! not allowed because parameter is defined as const struct and cannot call non-const member functions
}

int main()
{
  Person simon {"Simon", 26};
  //? we can directly access the member function from the created object 
  simon.increase_age_by_one();
  simon.greeting_from_person();
  simon.print_name();
  

  //* default initialization of member variables used for the following struct definition
  const Person patrick; //! structs can be const and also have to be initialized at creation
  // patrick.age = 11; //! the structs defined as const can not be modified
  //? calling member functions that modify member variables as side effects are also disallowed and result in compile error
  // patrick.increase_age_by_one();
  //? we also cannot call non-const member functions when working with a const struct
  // patrick.greeting_from_person();
  //? we can call const member functions with const structs
  //* because they garantee that no side effects occur
  patrick.print_name();
  

  return 0;
}