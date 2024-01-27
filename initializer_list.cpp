#include <iostream>
#include <string>
#include <string_view>
#include <initializer_list>

//? c++ automatically converts the initializer_list syntax to an object of std::initializer_list
//* std::initializer_list lifes in the <initializer_list> library

class Person{
    public:
        Person() = default;
        Person(std::string_view name, int age): m_name{name}, m_age{age}{}
        friend std::ostream& operator<< (std::ostream& out, const Person& p);
    private:
        std::string m_name{};
        int m_age{}; 
};


std::ostream& operator<< (std::ostream& out, const Person& p){
    out << "Person{ Name: " << p.m_name << ", Age: " << p.m_age << " }";
    return out;
}

class Personen{
    public:
        //? we create a constructor that is able to receive an intializer_list as argment
        //* std::initializer_list can be passed by value because they are inexpensive to copy
        Personen(std::initializer_list<Person> list):
        //? we use a delegate constructor to dynamically allocate space same as the length of the initializer_list
        Personen(static_cast<int>(list.size())){ //std::initializer_list.size() returns the length of the initializer_list //! uses direct initialization
            int count{0};
            //? we iterate through the initializer_list and assign all elements to the dynamically allocated array of Persons
            for(auto element : list){
                m_personen[count] = element;
                count++;
            }
            //! std::initializer_list does not support the subscript operator, but elements ca be accessed with foreach or .begin()
            //? the following is a valid workaround that is valid because .begin() returns a pointer to the first element 
            //? and on which we can use the subscript operator
            /*
            for(int count{}; count < list.size(); count++){
                m_personen[count] = list.begin()[count];
            }
            */
        }

        Personen(const Personen&)= delete; //! deletes default copy constructor
        Personen& operator= (const Personen&)= delete; //! deletes default copy assignment
        
        Personen& operator= (std::initializer_list<Person> list){
            if(static_cast<int>(list.size()) != m_length){
                delete[] m_personen;
                m_length = list.size();
                m_personen = new Person[m_length]{};
            }
            for(std::size_t index{}; index < list.size(); index++){
                m_personen[index] = list.begin()[index];
            }
            return *this;
        }

        Personen(int length): m_personen{new Person[length]}, m_length{length} {

        }

        ~Personen(){
            delete[] m_personen;
        }

        //? we define our own .begin and .end member functions to use the for_each syntax on our container class
        Person* begin(){
            return m_personen;
        }
        Person* end(){
            return m_personen + m_length;
        }

        Person& operator[](int index){
            return m_personen[index];
        }
    private:
        Person* m_personen;
        int m_length{};
};

int main(){

    Personen pList {{"simon", 33}, {"hans" ,25}};
    for(const auto& person : pList) {
        std::cout << person << std::endl;
    }
    std::cout << pList[0] << std::endl;

    //? list initialization favors initializer_list over other matching constructors
    //* if we would have a constructor Person(int value) and a constructor Person(std::initializer_list<int> value)
    //* then the call Person a{5}, would call the initializer_list constructor over the int constructor because it was created used list initialization
    //* however the call Person a(5), would call the int constructor because the creation was done via direct initialization

    //! when a class contains a initializer_list constructor be sure to adapt the copy assignment operator to support deep copying
    //! the default copy assignment operator only does a shallow copy, which means both objects will point to the same elements and when one goes out of scope the other will be left dangling
    
    //* 3 possible options:
    //* - delete the copy assignment operator
    //* - implement the copy assignment operator to support deep copying
    //* - implement a copy assignment operator with an initializer_list argument
    
    //~ when the default copy assignment operator is called following will happen:
    //~ compiler tries to convert the provided initializer_list to a temporary Personen object using the constructor that takes a initializer_list argument
    //~ then it performs a implicit shallow copy to the dynamically allocated array of the temporary Personen object, now both point to the same dynamically allocated array
    //~ after the temporary Personen object goes out of scope at the end of the copy assignment, it will delete its dynamically allocated array 
    //! which leaves the dynamically allocated array of the object assigned with the default copy assignment operator dangling
    pList = {{"a", 1}, {"b" ,2}, {"c" ,3}, {"d" ,4}};
    for(const auto& person : pList) {
        std::cout << person << std::endl;
    }
}