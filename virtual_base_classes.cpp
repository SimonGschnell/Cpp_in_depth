#include <iostream>
#include <string>
#include <string_view>

//~ classes inheriting a virtual base class will have a virtual table, what makes them larger by a pointer 
//? virtual base classes help to avoid the diamond problem with multiple inheritance:
//* the following Diagram shows how both Scanner and Printer can be PoweredDevices, and that Copier is both a Scanner and a Printer
//* But the problem here is that two instances of PoweredDevice are created because both the Scanner and Printer inherit that base class
//! and who would be responsible for maniging that common base class
//*         PoweredDevice
//*             /   \ 
//*      Scanner     Printer
//*             \   /
//*             Copier

//! TO avoid this problem we can inherit a class as a virtual base class by marking the class that is going to be inherited from as virtual

class PoweredDevice{
    private: 
        int m_pd{};
    public:
    PoweredDevice(int value): m_pd(value){
        std::cout << "PoweredDevice: " << m_pd << std::endl;
    }
};

class Scanner: virtual public PoweredDevice{
    private:
        int m_s{}; 
    public:
    //! The initialization list part that creates PoweredDevice is ignored when inherting it as a virtual base class
    //* however, if we would create an instance of Scanner the constructor would apply normal inheritance rules and construct the PoweredDevice from the Scanner 
    Scanner(int value): PoweredDevice{value}, m_s{value} {
        std::cout << "Scanner: " << m_s << std::endl;
    }
};

class Printer: virtual public PoweredDevice{
    private:
        int m_p{};
    public:
    //! The initialization list part that creates PoweredDevice is ignored when inherting it as a virtual base class
    //* however, if we would create an instance of Printer the constructor would apply normal inheritance rules and construct the PoweredDevice from the Printer
    Printer(int value): PoweredDevice{value}, m_p{value}{
        std::cout << "Printer: " << m_p << std::endl;
    }
};

class Copier: public Scanner, public Printer{
    
    public:
    //? When using virtual base classes, the most derived class is the one responsible for creating the base part
    //* so that only one instance of the base part is made
    Copier(int scanner_value, int printer_value, int value): PoweredDevice{value}, Scanner{scanner_value}, Printer{printer_value} {
        std::cout << "Copier" << std::endl;
    }
};

//! if we would add a more derived class to the inheritance hierarchy, the most derived class (this one) is responsible for the virtual base class construction now
class Test: public Copier{
    public:
    Test(int scanner_value, int printer_value, int value): Copier{scanner_value, printer_value,value}, PoweredDevice{value}{}
};

int main(){
    //* When creating a Copier object without inheriting virtual base classes, the following would be printed:
    // PoweredDevice created
    // Scanner created
    // PoweredDevice created
    // Printer created
    // Copier created
    //! 2 PoweredDevices are created because both Scanner and Printer inherit from PoweredDevice

    Copier c{1,2,3};
    


    return 0;
}