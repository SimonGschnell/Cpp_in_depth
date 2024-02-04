#include <iostream>
#include <string>
#include <string_view>

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
    Scanner(int value): PoweredDevice{value}, m_s{value} {
        std::cout << "Scanner: " << m_s << std::endl;
    }
};

class Printer: virtual public PoweredDevice{
    private:
        int m_p{};
    public:
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