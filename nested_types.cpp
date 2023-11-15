#include <iostream>

//! NESTED TYPES can not be forwatd declared (must be fully included in the header file where the class is defined)

//? if we define user-defined types like a type enum outside a class it is connected to, it is hard to infer how they are connected
enum class CarType{
    ferrari,
    porsche,
    bmw,
};

class Car{
    private:
        CarType m_type{}; 
    public:
        Car(CarType t): m_type{t}{}
        bool is_porsche() const { return m_type == CarType::porsche;}
        const CarType& getType() const { return m_type;} 
};

//? by defining the user-defined type inside the class we can use the class namespace as the qualified name and know that they are connected
class Fruit{
    public:
    //* notice the access specifier order, nested user-defined types have to be declared before they are used
    //? Best practice: define any nested types at the top of your class type
        enum Type{
            apple,
            cherry,
            orange
        };
    
    private:
        Type m_type{}; 

    public:
        Fruit(Type t): m_type{t}{}
        bool is_cherry() const { return m_type == cherry;}
        const Type& getType() const { return m_type;}    
    
};


int main(){

    Car c1{CarType::porsche};
    if(c1.getType() == CarType::bmw){
        // do something 
    } 

    //? this is better understandable
    Fruit f1{Fruit::apple};
    if(f1.getType() == Fruit::apple){
        // do something 
    } 
    


}