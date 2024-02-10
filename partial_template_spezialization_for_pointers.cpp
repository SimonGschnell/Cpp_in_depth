#include <iostream>
#include <string>
#include <string_view>

//? Definition of a templated class
//! but what happens if we use pointer type for the template type parameter
//* the constructors/destructors/print won't behave in the same way as for non pointer types
template <typename T>
class Storage
{
private:
    T m_value;
public:
    Storage(T value)
        : m_value { value }
    {
    }

    ~Storage()
    {
    }

    void print() const
    {
        std::cout << m_value << '\n';
    }
};

//~ We can use partial template specialization of the template class for pointer types
template <typename T>
//? partial template specialization with type T* (valid for all pointer types that are not have no fully specialized version already)
class Storage<T*>
{
private:
    T* m_value;
public:
    Storage(T* value)
        : m_value { new T{*m_value} }{}

    ~Storage()
    {
        delete m_value;
    }

    void print() const
    {
        std::cout << *m_value << '\n';
    }
};

//? we can fully specialize the template class for the pointer type char*
//* but what about all the other pointer types
template<>
Storage<char*>::Storage(char* value){
    //implement
}
template<>
Storage<char*>::~Storage(){
    //implement
}
template<>
void Storage<char*>::print() const {
    //implement
}




int main(){
    int* resource { new int{5}};
    Storage<int*> st {resource};
    *resource =10;
    st.print();
    std::cout << std::endl;


    return 0;
}