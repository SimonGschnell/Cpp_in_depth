#include <iostream>

class Person{
    public:
        Person(std::string_view name): m_name{name}{

        }
        std::string convertToString() const {
            return "Person: " + m_name;
        }
    private:
        std::string m_name{};
};

//! enable_if takes a boolean non-type template parameter and a template parameter 
template <bool B,typename T>
struct enable_if{
};

//! this is a partial template specialization of enable_if that defines uses true for the non-type template parameter
//! AND only defines a type alias type if the non-type template parameter is true
template <typename T>
struct enable_if<true,T>{
    //? if enable_if is called with a true non-type template parameter
    typedef T type;
};

//! by default every Type has its static value set to false 
template <typename T>
struct has_to_string{
    static const bool value = false;
};

//! this is a template specialization of has_to_string, that defines the static value true for the Person class
template<>
struct has_to_string<Person>{
    static const bool value = true;
};

//! We can make the following ToString function available to only those types that meet the enable_if constraint
//! every other type that does not meet the enable_if constraint results in a substitution failure 
//! SFINAE (substitution failure is not an error) means that the compiler will not throw an error when a substitution fails
//! in this case it would fail to substitute the ::type type alias because it is only defined for the types that meet the enable_if constraint
//* the default value =0 is used to create the fallback substitution failure and avoids a hard compiler error
//? note that the second parameter does not have a name because it is not used in the function, it is only used for template meta programming
template<typename T>
std::string ToString(const T& obj, typename enable_if<has_to_string<T>::value,T>::type* = 0){
    return obj.convertToString();
}

int main(){
    Person p1 {"simon"};
    std::string result {ToString(p1)};
    std::cout << result << std::endl;
    
}