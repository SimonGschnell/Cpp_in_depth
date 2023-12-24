#include <iostream>

class Cents {
    public:
        Cents(int value): m_value{value}{}
        
        //? because the increment operator ++ is a unary operator that changes the value of its operand we use a member function for the overloading
        Cents& operator++(); //? overloading prefix operator (++value)
        //! how differentiate between prefix and postfix increment / decrement operators 
        //* when the increment/decrement operator has a int parameter it is a postfix operator otherwise it is a prefix operator
        Cents  operator++(int); //? overloading postfix operator (value++)
    
        Cents& operator--(); //? overloading prefix operator (--value)
        Cents  operator--(int); //? overloading postfix operator (value--)

        friend std::ostream& operator<< (std::ostream& out, const Cents& c){
            out << "Cents: " << c.m_value;
            return out;
        }
    private:
        int m_value{};
};

//? implementations of the member functions operator overloads
Cents& Cents::operator++(){
    ++m_value;
    return *this;
}
//? inorder to increment the data members and to return the old state we have to store the old state when using postfix increment/decrement
Cents Cents::operator++(int){
    //* storing old values in temporary object
    Cents tmp {m_value};
    //? incrementing data members of object
    ++(*this);
    //? returning temporary object with old data members    
    return tmp;
}
Cents& Cents::operator--(){
    --m_value;
    return *this;
}
Cents Cents::operator--(int){
    Cents tmp{m_value};
    --(*this);
    return tmp;
}

int main(){
    Cents c{55};
    std::cout << "printing c: " << c << std::endl;
    std::cout << "printing ++c: " << ++c << std::endl;
    std::cout << "printing --c: " << --c << std::endl;
    std::cout << "printing c++: " << c++ << std::endl;
    std::cout << "printing c--: " << c-- << std::endl;
    std::cout << "printing c: " << c << std::endl;
    
    return 0;
}