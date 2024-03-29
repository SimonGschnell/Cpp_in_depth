#include <iostream>

//? Class template specialization allows us to specialize a template class for a particular data type
//* Class template specialization takes precedence over the generic version of the class Storage<T>
//? Class template specialization are completly independent classes, which means the access specifiers and the mehtods of the class can be customized

template <typename T>
class Storage
{
private:
    T m_value {};
public:
    Storage(T value)
      : m_value { value }
    {
    }

    void print()
    {
        std::cout << m_value << '\n';
    }
    void test()
    {
        std::cout << "test" << '\n';
    }
};

//! the publicly exposed interface of both classes don't have to be the same but should be, so that either class can be used in exactly the same manner 
template <> // the following is a template class specialization with no templated parameters
class Storage<double>{ // we are specialising class Storage for the type double
    private:
    double m_value {};
public:
    Storage(double value)
      : m_value { value }
    {
    }
    //? here we define a specific version of the print() member function for the type double
    void print()
    {
        std::cout << std::scientific << m_value << '\n';
    }
};

//! template member function specialisation
//* if we only want to have specific behavior for a member function of a class template
//? we don't have to redefine the whole class for single member functions
//? we can let the compiler implicitly specialise the class from Storage<T> and only provide a explicit specialisation for the member function

template<>
void Storage<bool>::print(){
    std::cout << std::boolalpha << m_value << std::endl;
}

int main()
{
    // Define some storage units
    Storage i { 5 }; //? we’ll get a version stenciled from the generic templated Storage<T> class
    Storage d { 6.7 }; //? we’ll get the specialized version we created of the class 
    Storage b { false }; //? implicitly specialised class with explicit specialisation of Storage<bool>::print()

    // Print out some values
    i.print();
    d.print();
    b.print();
}