#include <iostream>

int multiply_by_2(int x);

int add (int x, int y);

int main(){
    int number{};
    std::cout << "enter a number: "; 
    std::cin >> number;
    //std::cout << multiply_by_2(number) << '\n';
    //? the following line uses the add function from another file 
    //forward declaration of the add function that resides in add.cpp file
    std::cout << add(number,number) << '\n';
    return 0;
}

int multiply_by_2(int x){
    return x*2;
}