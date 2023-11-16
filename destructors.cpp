#include <iostream>

//? classes have another type of special member function that is called when the object is destroyed -> Destructors
//* a class can only have a single destructor
class Person{
    private:
        std::string m_name{};
        int m_age{};
    public:
        Person()= default;
        explicit Person(std::string_view name, int age=0): m_name{name}, m_age{age}{
            print();
            std::cout << "was created" << std::endl;
        }

        //? definition of the desctructor
        //* destructors have no return value / arguments and have the same as the class, preceeded by ~
        ~Person(){
            print();
            std::cout << "was destroyed" << std::endl;
        }
        //? there is also a implicit destructor which is just empty 
        // ~Person() = default;

        void print(){
            std::cout << m_name << " - " << m_age << " ";
        }
};

int main(){

    Person p1{"Simon",26};



    return 0;
}