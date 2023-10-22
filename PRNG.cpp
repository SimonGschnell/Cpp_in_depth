#include <iostream>

int predictable_sequence(){
    //* starts the sequence with an initial number
    static int inititial{5};

    //* generates a new predictable number in the sequence
    ++inititial;
    //* return the new generated number
    return inititial;
}

//? simple pseudo random number generation with a number sequence that is hard to resconstruate
int16_t simple_PRNG(){
    //! here we always use the same starting number for our number sequence, which means that the sequence we produce will always be the same
    //* same starting number == not seeded PRNG
    static int16_t init{20951};
    //? intentionally overflow the number for better unpredictability
    init = init * 109098 + 22677;
    //? return the newly generated number in the sequence
    return init % 32768; // we only return positive numbers
}

int main(){

    std::cout << "predictable sequence: " << predictable_sequence()<< " " << predictable_sequence() << " " << predictable_sequence() << std::endl;

    for ( int i = 0; i < 100; i++){
        std::cout << simple_PRNG() << " ";
        if (i % 10 == 0){
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
    return 0;
}