#include <iostream>
#include <string>
#include <string_view>

//? Sometimes we want ot be able to cast our user-defined types to other types
//* this is possible with overloading the typecase operator

class Cents{
    public:
        //? like we are able to implicitly convert a integer to a Cents object with the following constructor
        //* making the constructor explicit would prohibit this conversation
        Cents(int cents): m_cents{cents}{}

        //~ here we overload the typecast operator to convert a Cents object to an integer
        //* by returning the underlying integer data member
        //! overloading typecast operators have 3 rules:
        //* - non static 
        //* - they can not have any arguments but they still have the implicit this object
        //* - overloading the typecast operator does not have return types because it is already defined what to return in the typecast operator

        //~ it is best practice to always make typecasts explicit, unless we make a cheap conversion from one user-defined type to another
        //? we can also create typecast operators that convert a Cents object to a different user-defined type (if it makes sense)
        operator int() const { return m_cents; }

        //! just like constructos can be explicit, also typecast operators can be explicit to avoid implicit conversions
        explicit operator std::string() const { return std::to_string(m_cents);}
    
    private:
        int m_cents{};
};

class Euro{
    public:
        Euro (int eur): m_euro{eur}{}

        //? overloads the typecase operator to convert a Euro object to a Cents object
        operator Cents() const {
            return m_euro * 100;
        }
    private:
        int m_euro{};
};

//* implementation of a function that explicitly takes an integer and prints it
void printInt (int value){
    std::cout << value << std::endl;
}

void printDouble (double value){
    std::cout << value << std::endl;
}

int main () {

    //? now that the Cents class has the typecast operator overloaded for integer conversions
    //* we can pass a Cents object to a function that accepts integers as parameters 
    Cents cent {44};
    printInt(cent);

    //? now we can also explicitly cast the object to an integer with the overloaded typecast operator
    int value { static_cast<int>(cent)};

    //? we even can pass it to a function that explicitly takes doubles as arguments 
    //* because the cents object can be converted to an int and an int can be converted to a double
    printDouble(cent);

    //? will use cent as int and make a narrow conversion from integer to char and put , inside the cent_string variable
    std::string cent_string{cent};
    std::cout << cent_string << std::endl;

    //? with static_cast we are explicitly converting the cent user-defined type to std::string which will call our defined explicit typecast operator
    std::string explicit_cent_string{ static_cast<std::string>(cent)};
    std::cout << explicit_cent_string << std::endl;
   
    return 0;
}