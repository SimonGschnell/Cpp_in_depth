#include <iostream>
#include <iomanip>

bool approximatelyEqualAbs(double a, double b, double absEpsilon);

int main(){

    double d1{100.0 - 99.99}; // shoutld equal to 0.1
    double d2{10.0 - 9.99}; // should equal to 0.1

    //? d1 won't be equal to d2 because floating point numbers have numerical errors
    if(d1 == d2){
        std::cout << "d1 == d2" << std::endl;
    }else if (d1 < d2){
        std::cout << "d1 < d2" << std::endl;
    }else if (d1 > d2){
        std::cout << "d1 > d2" << std::endl;
    }

    //! Avoid using == and != to compare floating point numbers 
    double f1{100.0 - 99.99};
    double f2{10.0 - 9.99};

    std::cout << ((f1 == f2) ? "equal" : "not equal") << std::endl;
    std::cout << std::setprecision(16);
    std::cout << f1 << std::endl;
    std::cout << f2 << std::endl;

    //! It is ok to compare low-precision floating point literals of the same value and type
    constexpr double gravity {9.8};
    //conparison with literal
    if (gravity == 9.8){
        std::cout << "both floating point literals have the same value" << std::endl;
    }

    std::cout << ((approximatelyEqualAbs(f1, f2, 0.00001)? "numbers a close enough": "numbers are not close enough") )<< std::endl;
    
    


    return 0;
}

//! to compare floating point numbers we use a approximation function that checks if the numbers a close enough 
//* using an epsilon as delta between the numbers
#include <cmath> // for std::abs()

// absEpsilon is an absolute value
bool approximatelyEqualAbs(double a, double b, double absEpsilon)
{
    // if the distance between a and b is less than or equal to absEpsilon, then a and b are "close enough"
    return std::abs(a - b) <= absEpsilon;
}