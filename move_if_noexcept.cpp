#include <iostream>
#include <memory>
#include <stdexcept>
#include <utility>

//? std::move_if_no_except is a way to ensure a strong exception guarantee that leaves the old state of the objects as the original state

//? std::move_if_no_except behaves the same as std::move 
//* if the object that is going to be moved has a noexcept move constructor
//* if the object that is going to be moved has only a move constructor and no copy constructor even if the move constructor isn't noexcept

//~ classes like std::vector use std::move_if_noexcept and can be optimized if they hold objects that have a non-throwing noexcept move constructor
//* if the std::vector holds object that don't have a non-throwing noexcept move constructor, then the objects have to be copied around

class NoExceptMoveClass{
    private:
        std::unique_ptr<int> m_value{};
    public:
        NoExceptMoveClass(int value) : m_value{std::make_unique<int>(value)}{}

        //? move constructor that takes ownership of another std::unique_ptr 
        //* marked as noexcept 
        NoExceptMoveClass(NoExceptMoveClass&& other) noexcept: m_value{std::move(other.m_value)}{
            std::cout << "Move Constructor of NoExceptMoveClass was called" << '\n';
        }

        //? copy constructor that makes a deep copy of the resource the std::unique_ptr is holding
        NoExceptMoveClass(const NoExceptMoveClass& other) : m_value{std::make_unique<int>(*other.m_value)}{
            std::cout << "Copy Constructor of NoExceptMoveClass was called" << '\n';
        }
        int operator* (){
            return *m_value.get();
        }
};

class MoveClass{
    private:
        std::unique_ptr<int> m_value{};
    public:
        MoveClass(int value) : m_value{std::make_unique<int>(value)}{}

        //? move constructor that takes ownership of another std::unique_ptr 
        //* not marked as noexcept therefore it is a potentially throwing function
        MoveClass(MoveClass&& other): m_value{std::move(other.m_value)}{
            std::cout << "Move Constructor of MoveClass was called" << '\n';
        }

        //? copy constructor that makes a deep copy of the resource the std::unique_ptr is holding
        MoveClass(const MoveClass& other) : m_value{std::make_unique<int>(*other.m_value)}{
            std::cout << "Copy Constructor of MoveClass was called" << '\n';
        }
        int operator* (){
            return *m_value.get();
        }
};

int main(){

    NoExceptMoveClass m1{10};
    NoExceptMoveClass m2{std::move_if_noexcept(m1)};    // moves
    std::cout << *m2 << std::endl;

    MoveClass m3{10};
    MoveClass m4{std::move_if_noexcept(m3)};    // copies
    std::cout << *m2 << std::endl;
    

}