#include <iostream>
//? importing a class through a header definition
#include "class_header.h"

//! A class defined in a source file is only usable in the same source file
//? header files are used to use classes in multiple source files
//* therefore a class is broken down to a header file with the definition of the class and a .cpp file with the implementation of the detailed functions

//? C++ allows to seperate the public interface of a class from the internal details
class Car{
    private:
        std::string m_model{};
        int m_price{};
    public:
        //* only defining the header of the methods we want to separate from the definition
        Car(std::string_view model, int price);
        //* same for method print
        void print();
        //! getter and setter are left in the definition because of their simplicity
        int getPrice(){
            return m_price;
        }
        void setPrice(int price){
            m_price = price;
        }
};

//? we refactored the details of the class outside of the public interface
//* member functions outside of the class must have qualified names with its class name using the scope-resolution operator ( :: )
Car::Car(std::string_view model, int price): m_model{model}, m_price{price}{}

void Car::print()
{
            std::cout << "Car{model:"<< m_model << " price:"<<m_price<<"}"<<std::endl;
}


int main(){

    //? Now we are able to use the class that was defined in the header file "class_header.h" in multiple source files
    Person p1{"Simon",26};
    p1.print();
    p1.add_age(3).subtract_age(1);
    p1.print();

}