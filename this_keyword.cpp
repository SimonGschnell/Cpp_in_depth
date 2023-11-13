#include <iostream>

//? how does the compiler know how to call member functions 
//! the compiler implicitly uses a hidden this pointer to the class object to perform actions on the object

class Simple{
    private:
        int m_id{};
    public:
        Simple(int id): m_id{id}{}

        void set_id(int m_id){
            //? this can come into use when the parameter name is the same as the data member
            //* with this we can explicitly say that we want to use the data member m_id of this object
            this->m_id=m_id;
        }
        int get_id(){
            return m_id;
        }
        void print(){
            std::cout << m_id << std::endl;
            //? the version that the compiler implicitly converts:
            //* std::cout << this->m_id << std::endl;
            //* this is a pointer that contains the objects data, same as (*this).m_id 
        }
        //? another use case of the this keyword
        //? is to return the *this object to make member functions able to chain on the object
        //* something like obj.chain_add(2).chain_add(2) would add 2 and then again add 2 to the class object
        //! instead if the member function would return void, the chain_add() function would have to be called 2 times in different statements
        Simple& chain_add(int value){
            m_id += value;
            return *this;
        }

        Simple& chain_subtract(int value){
            m_id -= value;
            return *this;
        }
};

int main(){
    Simple s1{1};
    s1.set_id(3);
    //? also this call to the member function is implicitly converted by the compiler
    //* the original version 
    // Simple::set_id(&s1,3);
    //* the member function then looks like this:
    // void set_id(Simple* const this, int id){ ... }

    
    s1.print();
    //? we are chaining the member functions by returning the this* object after a call to the member function
    //* s1 starts with 3 
    //* we chain the operations: +1 +2 -1 +2 which results in 7
    s1.chain_add(1).chain_add(2).chain_subtract(1).chain_add(2);
    s1.print(); // will print 7
    

    return 0;
}