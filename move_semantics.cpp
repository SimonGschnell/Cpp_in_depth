#include <iostream>

//? C++11 defines two new functions for move semantics:
//* move Constructor
//* move assignment operator
//? their goal is to move ownership of the resource which is less expensive than making a copy
//* the functions take non-const R-Value references as parameters to move ownership

template <typename T>
class Person{
public:
    Person(T* value): m_resource{value}{

    }

    //? creating a move constructor that takes a r-value reference 
    //* noexcept is a keyword that indicates that the function is fail-safe and the compiler and aligorithms can use that to optimize their usage
    Person(Person&& value) noexcept
    // moves resource of r-value reference to own ownership
    :m_resource{value.m_resource}{
        // sets the r-value reference resource to nullptr
        value.m_resource = nullptr;
    }

    //? creating a move assignment operator that also takes a r-value reference
    Person& operator= (Person&& value) noexcept {
        // check if it is not an self assignment
        if(this == &value){
            return *this;
        }
        // delete old resource
        delete m_resource;
        // move r-value resource to own ownership
        m_resource = value.m_resource;
        // sets the r-value reference resource to nullptr
        value.m_resource = nullptr;
        // returns 
        return *this;
    }

    //? releasing the resource when the smartPointerClass "Person" goes out of scope
    ~Person(){
        delete m_resource;
    }
    T* operator->(){
        return m_resource;
    }
    T& operator*(){
        return *m_resource;
    }
private:
    T* m_resource{};
};

class Resource{
    public:
    Resource(){
        std::cout << "Resource aquired" << std::endl;
    }
    ~Resource(){
        std::cout << "Resource deallocated" << std::endl;
    }
};

Person<Resource> createSmartPointer(){
    Person p {new Resource{}}; //* calls the normal constructor
    //? returns the Person by value and calls the move constructor
    return p;
}

int main(){

    Person<Resource> test{new Resource{}}; //* calls the normal constructor
    Person<Resource> p{std::move(test)}; //? calls the move constructor
    p= createSmartPointer(); //? calls the move assignment operator


    return 0;
}