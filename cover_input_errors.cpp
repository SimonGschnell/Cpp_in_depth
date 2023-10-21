#include <iostream>
#include <limits>

void ignoreLine(){
    //? ignores all input possible in streamsize until newline
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
}

double get_double(){
    while(true){
        double x{};
        std::cout << "Enter a double number:";
        std::cin >> x;
        //? checks whether the input was a wrong format
        //! goes into failure mode
        if(!std::cin){

            //! if the steam was closed with ctrl+d we can't revover with std::cin.clear()
            //? we have to cover it separately
            if(std::cin.eof()){
                std::exit(0); // end the program now
            }

            //? set cin back to normal void
            std::cin.clear();
            //* and clear the last wrong input
            ignoreLine(); // ignore the rest to avoid errors with residue buffer
        
        }else{
            ignoreLine();
            return x;
        }  
    }
}

void printResult(double x, char operation, double y);

char get_operator(){
    while(true){
        char x{};
        std::cout << "Choose an operator (+|-|*|/):";
        std::cin >> x;

        if(!std::cin){
            if(std::cin.eof()){
                std::exit(0); // quit program 
            }
            std::cin.clear(); // go back to normal mode after failure
            
        }
        ignoreLine();
        switch (x)
        {
        case '+':
        case '-':
        case '*':
        case '/':
            return x;
        
        default:
            std::cout << "Invalid input for operator" <<std::endl;
            break;
        }
    }
}

int main(){
    double first_number{get_double()};
    char operation{get_operator()};
    double second_number{get_double()};

    printResult(first_number,operation,second_number);


    return 0;
}

void printResult(double x, char operation, double y)
{
    switch (operation)
    {
    case '+':
        std::cout << x << " + " << y << " is " << x + y << '\n';
        break;
    case '-':
        std::cout << x << " - " << y << " is " << x - y << '\n';
        break;
    case '*':
        std::cout << x << " * " << y << " is " << x * y << '\n';
        break;
    case '/':
        std::cout << x << " / " << y << " is " << x / y << '\n';
        break;
    }
}