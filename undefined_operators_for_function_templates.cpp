#include <string>
#include <string_view>
#include <iostream> 

class Cents{
    private:
        int m_cents{};
    public:
        Cents(int value): m_cents{value}{}
        friend std::ostream& operator << (std::ostream& out, const Cents& cent);
};

std::ostream& operator << (std::ostream& out, const Cents& cent){
    out << cent.m_cents;
    return out;
}

//? function template that instantiates a function which compares two types based on the operator<
template <typename T>
T& max (T& t1, T& t2){
    return t1 < t2 ? t1 : t2;
}

int main () {

    Cents c1{10};
    Cents c2{20};
    //! when we try to call the max function on a user-defined type that does not implement the operator< 
    //! the compiler fails to instantiate a function version that can compare two Cents because the operator< is not defined for that type
    //std::cout << max(c1,c2) << std::endl;

}