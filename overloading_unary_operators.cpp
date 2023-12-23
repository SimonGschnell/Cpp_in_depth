#include <iostream>

//? unary operators are operators that use one operand
//* unary operators are: +, - and ! , where + and - are used for the sign of an value typically

class Euro{
    public:
        Euro(int value): m_euros{value}{}
        Euro operator- () const{
            //* we overload the unary operator - as a member function, where the left most operand is the implicit this object
            //? implicitly converts int to Euro object because the constructor is not explicit
            return -m_euros;
        }
        Euro operator+ () const {
            //? here we implement the overloaded operator+
            return +m_euros;
        }
        int get_amount() {return m_euros;}

        //? we can use the unary operator! to check whether an object evaluates to true or false depending on the data member of the object 
        bool operator! () const {
            return m_euros <= 0;
        }
    private:
       int m_euros{};
};

int main (){

Euro eur1 {4};
//? this will print -4 because the unary - operator with an Euro object will create and return a new Euro object with the same negative amount
std::cout << (-eur1).get_amount() << std::endl;

if(!eur1){
    std::cout << "eur1 is 0 or negative" << std::endl;
}
else{
    std::cout << "eur1 is greater than 0" << std::endl;
}

return 0;
}