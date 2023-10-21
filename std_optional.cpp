#include <iostream>
#include <optional>
#include <vector>

std::optional<std::string> is_in_fruitbasket(std::string fruit){
        static std::vector<std::string> fruitbasket = {"apples", "bananas", "oranges", "dragonfruits", "kiwi"};
        for (std::string f : fruitbasket){
            if(f == fruit){
                return f;
            }
        }
        return std::nullopt;
}

int main (){

    std::cout << std::boolalpha; //prints bools as strings
    std::cout << "is apples in the basket? " << is_in_fruitbasket("apples").has_value() << std::endl;
    std::cout << "is pflaumen in the basket? " << is_in_fruitbasket("pflaumen").has_value() << std::endl;

    return 0;
}