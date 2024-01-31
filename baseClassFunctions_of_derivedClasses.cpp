#include <iostream>
#include <string>
#include <string_view>

//? Curiously Recuring Template Pattern can be used to call the derived methods from the base class
//* somewhat like an Interface 
template <typename T>
class AnimalCRTP{
    public: 
        void speak() { static_cast<T*>(this)->speak(); }
    
};

//? Base class Animal
class Animal{
    private:
        std::string m_name{};
    protected:
        Animal (std::string_view name): m_name{name}{}
    public: 
        std::string_view getName(){ return m_name; }
        void speak() { std::cout << "??" << std::endl; }
    
};

//? Derived class Cat
class Cat : public AnimalCRTP<Cat>, public Animal {
    private:
    
    public:
        Cat(std::string_view name ): Animal(name){}
        void speak() {
            std::cout << "miau" << std::endl;
        }
};

//? Derived class Dog
class Dog : public AnimalCRTP<Dog>, public Animal {
    private:
        
    public:
        Dog(std::string_view name ): Animal(name){}
        void speak() {
            std::cout << "wuff" << std::endl;
        }

};

template <typename T>
void AnimalSpeak(const AnimalCRTP<T>&);

int main(){
    Dog d {"doggy"};
    Dog& dog_ref {d};      //Reference to dog object
    Dog* dog_ptr {&d};     //Pointer to dog object
    
    d.speak();             //prints wuff
    dog_ref.speak();       //prints wuff
    dog_ptr->speak();      //prints wuff

    //? we can assign a derived class object to a Base class object
    //! which is very useful, in order to store the common parts of objects that inherit from the same class
    //* we can create both references and pointers pointing to the derived objects
    Animal& base_ref {d};  //Animal reference to Dog object
    Animal* base_ptr {&d}; //Animal pointer to Dog object
    
    //? when the base class tries to call the member function, only the member function in the Animal (Base) class is visible to the compiler 
    //~ Virtual functions are used excatly to overcome this behaviour
    base_ref.speak();      //prints ??
    base_ptr->speak();     //prints ??

    AnimalCRTP<Dog>& CRTPbase_ref {d};  
    AnimalCRTP<Dog>* CRTPbase_ptr {&d}; 
    
    //? using the CRTP to call the speak() member function on any type of Animal object
    CRTPbase_ref.speak();      //prints wuff
    CRTPbase_ptr->speak();     //prints wuff

    return 0;
}

//? using the CRTP to call the speak() member function on any type of Animal object
template<typename T>
void AnimalSpeak(const AnimalCRTP<T>& a){
    a.speak();
}