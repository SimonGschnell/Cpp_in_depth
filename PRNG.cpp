#include <iostream>
#include <random>
#include <chrono>

int predictable_sequence(){
    //* starts the sequence with an initial number
    static int inititial{5};

    //* generates a new predictable number in the sequence
    ++inititial;
    //* return the new generated number
    return inititial;
}

//? simple pseudo random number generation with a number sequence that is hard to resconstruate
unsigned int simple_PRNG(){
    //! here we always use the same starting number for our number sequence, which means that the sequence we produce will always be the same
    //* same starting number == not seeded PRNG
    static unsigned int init{2951};
    //? intentionally overflow the number for better unpredictability
    init = 8253729 * init + 2396403;
    //? return the newly generated number in the sequence
    return init % 32768; // we only return positive numbers
}

int main(){

    //? mt19937 produces unsigned 32bit integers
    //? mt19937_64 produces unsigned 64bit integers
    // using a standard library pseudo random number generator
    //! we seed the mt rng with a clock timer
    std::mt19937 mt{static_cast<std::mt19937::result_type>(std::chrono::steady_clock::now().time_since_epoch().count())}; 
    
    //? for an uniform distribution over a range 
    //* for simulating a dice roll
    std::uniform_int_distribution ud{1,6};

    std::cout << "predictable sequence: " << predictable_sequence()<< " " << predictable_sequence() << " " << predictable_sequence() << std::endl;

    for ( int i = 1; i <= 30; i++){
        std::cout << simple_PRNG() << " ";
        if (i % 10 == 0){
            std::cout << std::endl;
        }
    }

    //? generating random numbers with the Mersenne Twister
    for (int i = 1; i <= 25; i++){
        //* mt() is a concise syntax for calling the function mt.operator(), 
        //* which for these PRNG types has been defined to return the next random result in the sequence.
        std::cout << mt() << " ";
        if(i % 5 == 0) std::cout << '\n';
    }

    for (int i = 1; i <= 30; i++){
        std::cout << ud(mt) << " ";
        if(i % 6 == 0) std::cout << '\n';
    }


    std::cout << std::endl;
    return 0;
}