#include <memory>
#include <string>
#include <iostream>


//! std::shared_ptr has a problematic, when shared_ptr's create a circular dependency 
//! when std::shared_ptr's create a circular dependency, they do not deallocate the resource because the next in the cycle will hold a reference to the previous

class Person{
    public:

        Person(std::string_view name): m_name{name}{
            std::cout << "Person allocated" << std::endl;
        }
        ~Person(){
            std::cout << "Person deallocated" << std::endl;
        }

        friend bool partnerUp(std::shared_ptr<Person>& p1, std::shared_ptr<Person>& p2){
            if(!p1 || !p2) return false;
            //? creates circular dependency
            p1->m_partner = p2;
            p2->m_partner = p1;
            return true;

        }
    private:
        std::string m_name{};
        std::shared_ptr<Person> m_partner;
};


//! to avoid circular dependencies, we can use std::weak_ptr which observe objects but don't own them
//? std::shared_ptr only count other shared_ptr's holding the object, weak_ptr's don't count
//? therefore shared_ptr can deallocate a resource even if a weak_ptr still points to it and becomes invalid
//* std::weak_ptr has access to the reference count for an object, the member function .expired() can tell us whether the weak_ptr dangling or not

//! weak_ptr's cannot be used directly, they have to be converted to shared_ptr using the member function .lock()
class Person2{
    public:

        Person2(std::string_view name): m_name{name}{
            std::cout << name << " allocated" << std::endl;
        }
        ~Person2(){
            std::cout << m_name << " deallocated" << std::endl;
        }

        friend std::ostream& operator<< (std::ostream& out, const Person2& person){
            out << person.m_name;
            return out;
        }

        friend bool partnerUp(std::shared_ptr<Person2>& p1, std::shared_ptr<Person2>& p2){
            if(!p1 || !p2) return false;
            //? we assign the shared_ptrs to the weak_ptrs
            p1->m_partner = p2;
            p2->m_partner = p1;
            return true;

        }

        //? uses .lock() on the weak_ptr to make it usable as a shared_ptr
        std::shared_ptr<Person2> getPartner(){
            return m_partner.lock();
        }

        std::weak_ptr<Person2>& getWeakPartner(){
            return m_partner;
        }

    private:
        std::string m_name{};
        //? stores the partner as a weak_ptr
        std::weak_ptr<Person2> m_partner;

};

int main(){

    auto simon {std::make_shared<Person>("Simon")};
    auto rosie {std::make_shared<Person>("Rosie")};

    partnerUp(simon, rosie);
    //* both simon and rosie go out of scope here 
    //* rosie goes out of scope but does not delete rosie because simon's m_partner shared_ptr points to it
    //! l-value rosie is no longer accessible 
    //* simon goes out of scope but does not delete simon because rosie's m_partner shared_ptr points to it, even though l-value rosie is no longer accessible
    //! l-value simon is no longer accessible
    //? both simon's m_partner and rosie's m_partner are still owning each others reference even though they are not accessible anymore
    



    auto simon1 {std::make_shared<Person2>("Simon")};
    {
        auto rosie1 {std::make_shared<Person2>("Rosie")};

        partnerUp(simon1, rosie1);    

        //? even though we saved the generated shared_ptr from the weak_ptr in the l-value partner, 
        //? we can be sure that the l-value will go out of scope at the end of the function
        auto partner = simon1->getPartner();
        std::cout << "simon's partner is: " << *partner << std::endl;
    }//! rosie1 goes out of scope here and makes simon->m_partner invalid
    
    //? .expired() will return true when it doesn't point to a valid object anymore
    //* this is special to std::weak_ptr
    //! with dumb pointers - even if they hold any value it can not be asured that the pointer is dangling before dereferencing
    //* that's why is it dangerous to use dumb pointers
    std::cout << std::boolalpha;
    std::cout << simon1->getWeakPartner().expired() << std::endl; 

    

    return 0;
}