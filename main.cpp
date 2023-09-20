#include <iostream>
using namespace std;

// functions have to be defined before they can be called
// we can use function prototypes to define functions without logic

//prototype for add function that adds int 2 numbers
int add(int a,int b);
//overloading prototype function that adds the value of 2 int pointers
int add(int* x,int* y);

auto println =[](string s){
    std::cout << s << std::endl;
};

int main(){
    println("this is a lambda function that is called println and calls cout");
    int number;
    cout << "Enter a number";
    cin >> number;
    cout << "The Number is: " << number << std::endl;



    //if else example
    if (number > 5){
        cout << "The number you entered was greater than 5." << std::endl;

    }else if(number == 1){
        cout << "The number you entered was exactly one." << std::endl;
    }
    else{
        cout << "The number you entered was lower than 5." << std::endl;
    }

    //while loop example
    cout << "while loop" << std::endl;
    while(number > 0 ){
        cout << number << " - ";
        number -=1;
    }
    cout << endl;

    // for loop example
    cout << "for loop" << endl;
    for ( int i = 10; i>number; i--){
        cout << i << " - ";

    }
    cout << endl;

    // switch statement example
    switch ( number ){
    case 1: cout << "number == 1" << endl; break;
    case 0: cout << "number == 0" << endl; break;
    default: cout << "number is neither 1 nor 0" << endl; break;
    }

    cout << "3 + 4 = " << add(3,4) << endl;
    int n1 = 3;
    int n2 = 4;
    int* n1_ptr = &n1;
    int* n2_ptr = &n2;
    cout << "pointer to 3 + pointer to 4 = " << add(n1_ptr,n2_ptr) << endl;

    return 0;

    
}

//function to add 2 numbers example
int add (int n1, int n2) {
    return n1 + n2;
}

//function with pointers example
int add (int* n1, int* n2) {
    return *n1 + *n2;
}