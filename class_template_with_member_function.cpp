#include <iostream>

//? usage of a class template
template <typename T>
class Pair{
    public:
        //? we can freely use the template parameter in the class itself
        Pair(const T& first, const T& second):m_first{first},m_second{second}{}
        //* it is safer to pass template parameters as const references to not make expensive copies in case the passed type is big
        bool isEqual(const Pair<T>& other);
    private:
        T m_first{};
        T m_second{};
};

//! when implementing a member function outside of the class we have to resupply the template parameter declaration and use the fully qualified name of the function
//* template functions are implicitly inline therefore there won't be problems when implementing the member function template outside of the class
//? member function templates should be defined just below the class definition to understand their usage
template <typename T>
bool Pair<T>::isEqual(const Pair<T>& other){
    return m_first == other.m_first && m_second == other.m_second;
}

int main(){
    using namespace std::literals;
    Pair<std::string> p1{"a"s, "b"s};
    Pair<std::string> p2{"a"s, "b"s};
    std::cout << std::boolalpha;
    std::cout << p1.isEqual(p2) << std::endl;

}