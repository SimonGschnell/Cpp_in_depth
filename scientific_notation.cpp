#include <iostream>
#include <iomanip>
#include <cstdint>

int main(){

    //? scientific notations are used to make really small or big numbers more compact
    // significant x10 ^ exponent
    //* 1.2 x10 ^ 4 would be 12000 (1.2 x 10000)

    //? c++ uses the letter "e" for times 10 to the power of
    uint32_t positive_sn = 1.2e4;

    //? for negative numbers
    int32_t negative_sn = 5e-2; //is equivalent to 5 * 10⁻², which is 5 / 10², or 0.05

    //! when converting numbers to scientific notation we don't cut the trailing zeros if the number had decimal points
    //* this is because the more decimal points in the significant, the more precise the result 
    
    return 0;
}