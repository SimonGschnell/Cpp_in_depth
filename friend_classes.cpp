#include <iostream>

//? A friend class is a class that can access the private and protected members of another class

class Storage{
    public:
        Storage(int int_val, double double_val):m_nvalue{int_val}, m_dvalue{double_val}{}
        
        //? making the class Display a friend of Storage
        friend class Display;

    private:
        int m_nvalue{};
        double m_dvalue{};
};

class Display{
    public:
        explicit Display(bool value):m_display{value}{}

        //? member functions of Display have now access to all the members of Storage objects
        void display_storage(const Storage& o){
            if(m_display){
                //? accessing private Storage data member
                std::cout << o.m_nvalue << std::endl;
            }else{
                std::cout << o.m_dvalue << std::endl;
            }
        }

        void setDisplay(bool value){
            m_display = value;
        }

    private:
        bool m_display{};
};


int main(){

    Storage s1{1,9.9};
    Display d1{false};

    //? because Display is a friend class of Storage, member functions of Display have access to members of Storage
    //* This way we can logically separate the two classes instead of having the whole logic in 1 cluttered class
    d1.display_storage(s1);
    d1.setDisplay(true);
    d1.display_storage(s1);

    return 0;
}