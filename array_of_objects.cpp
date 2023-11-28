#include <iostream>
#include <array>

class Person{
    public:
        
        constexpr Person(std::string_view name, int age): m_name{name}, m_age{age} {}
        std::string_view getName() const { return m_name;}
        void setName(std::string_view name ){ m_name =name;}

    private:
        std::string m_name{};
        int m_age{};

};

struct PersonStruct{
    std::string name{};
    int age{};
} ;

int main(){
    
    std::array personen{ Person("simon",26),Person("peter",22),Person("natalie",33),Person("susi",10)};
    //? when initializing an std::array with struct we have to add the struct name
    std::array struct_personen{PersonStruct{"peter",1},PersonStruct{"hans",2}};

    //? A std::array is defined as a struct that contains a single C-style array member
    /* 
    template<typename T, std::size_t N>
    struct array
    {
        T implementation_defined_name[N]; // a C-style array with N elements of type T
    } 
    */


    //* when leaving away the name, the compiler will pass the first element to the list initialization of the underlying C-like array that is being used by std::array
    //* by wrapping the elements in additional brackets {} this can be avoided
    std::array<PersonStruct,2> struct_personen2{ { {"peter",1},{"hans",2} } };

    std::cout << "liste der personen: " << std::endl;
    for(const auto& person : personen){
        std::cout << "Person - " << person.getName() << "\n";
    }
    std::cout << std::endl;


    return 0;
}