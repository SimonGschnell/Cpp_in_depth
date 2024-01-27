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
        Personen(std::initializer_list<Person> list):
        //? we use a delegate constructor to dynamically allocate space same as the length of the initializer_list
        Personen(static_cast<int>(list.size())){ //* std::initializer_list.size() returns the length of the initializer_list
            int count{0};
            //? we iterate through the initializer_list and assign all elements to the dynamically allocated array of Persons
            for(auto element : list){
                m_personen[count] = element;
                count++;
            }
        }
        Personen(int length): m_personen{new Person[length]}, m_length{length} {

        }
        //? we define our own .begin and .end member functions to use the for_each syntax on our container class
        Person* begin(){
            return m_personen;
        }
        Person* end(){
            return m_personen + m_length;
        }
    private:
        Person* m_personen;
        int m_length{};
};

int main(){

    Personen pList {{"simon", 33}, {"hans" ,25}};
    for(auto person : pList) {
        std::cout << person << std::endl;
    }

}