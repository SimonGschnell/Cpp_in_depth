#include <iostream>

//! The technical difference between structs and classes in c++ is:
//* A class defaults its members to private, whereas a struct defaults its members to public.

//? c++ has three access specifiers levels
//* public / private and protected
//? access specifiers are used to determine if it is permited to access a data member and from where 

//! structs should avoid access specifiers otherwise they would lose the aggregate characteristic
struct Person {
    //? ALL struct members of structs are public by default
    std::string name {}; // default public
    int age {}; // default public

    //! it is a common convention to name private members with a m_ prefix to differentiate them from other identifiers

    void print_person() const { // default public
        std::cout << "the name of the person is: " << name << " and the age is: " << age << std::endl;
    }
};

enum class Color { Red, Green, Blue, Yellow, Silver, Black, White};
std::ostream& operator<<(std::ostream& os, const Color& color){
    switch (color){
        case Color::Red: os << "Red"; break;
        case Color::Green: os << "Green"; break;
        case Color::Blue: os << "Blue"; break;
        case Color::Yellow: os << "Yellow"; break;
        case Color::Silver: os << "Silver"; break;
        case Color::Black: os << "Black"; break;
        case Color::White: os << "White"; break;
        default: os << "unknown color"; break;
    }
    return os;

}

//! Classes should generally only have private data members and public member functions like setters and getters
//? class members are default private instead
class Car{
    
    //* we can define what members should have the public/private access specifier within the class by creating public/private blocks
    
    public :
        void print() const{ //? inside the public access specifier block
        //* the member function is allowed to access the private class member because they are in the same scope
        std::cout << "the car is " << color << " and the manufacturer of the car is: " << manufacturer << std::endl;
        }

        //! Access specifier level are per-class not per-object
        void car_crash(Car& car2) const {
            //* we have direct access to the private manufacturer data member of the car2 object
            std::cout << manufacturer << " crashed with " << car2.manufacturer << std::endl;
        }

        void set_manufacturer(std::string value){
            manufacturer = value;
        }

    private :
        std::string manufacturer{ "Porsche" }; //? default private
        Color color { Color::Black }; //? default private

        void print_car(){ //? default private
            //* the member function is allowed to access the private class member because they are in the same scope
            std::cout << "the car is " << color << " and the manufacturer of the car is: " << manufacturer << std::endl;
        }
};

int main(){

    Person simon { "Simon" , 26 };
    simon.age = 10; //? public members are free to use outside of the scope of the struct
    simon.print_person(); //? public access to member functions that are default public in structs

    //Car porsche {"Porsche" , Color::Black}; //! compiler error
    //! beacuse the class has now default private members is no aggregate anymore and cannot be aggregate initialized
    
    Car porsch {};
    porsch.print(); //access to the public member function
    //porsch.color = Color::Red; //! color data member in class Car is set to private and not accessible from outside

    Car fiat{};
    fiat.set_manufacturer("Fiat");
    //? access specifiers are per-class not per-object --- direct access to private data members of passed Car object inside class
    fiat.car_crash(porsch);

    return 0;
}