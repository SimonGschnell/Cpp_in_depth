#include <iostream>
#include <memory>


//? std::shared_ptr lifes in the <memory> header like unique_ptr
//* shared_ptr is used when a resource is owned by multiple smart pointers, 
//* the resource is only deallocated as soon as the last shared_ptr owning the resource goes out of scope 

class Resource{
    public:
    Resource(){
        std::cout << "Resource aquired" << std::endl;
    }
    ~Resource(){
        std::cout << "Resource deallocated" << std::endl;
    }
    friend std::ostream& operator<< (std::ostream& out, const Resource& res){
        out << "Resource" << std::endl;
        return out;
    }
};

int main(){
    Resource* res { new Resource()};
    //? creating a shared_ptr to hold the resource
    std::shared_ptr<Resource> shared1 {res};
    
    //? like make_unique exists for unique_ptrs, in C++11 make_shared exists for shared_ptrs (inside the <memory> library )
    //* std::make_shared is safer because there is no way to create to shared_ptrs to the same resource
    auto another_smart_pointer {std::make_shared<Resource>()};

    {
        //? creating another shared_ptr pointing to out dynamically allocated resource
        //! second shared_ptr has to be initialized with another shared_ptr that owns the resource, to share the resource
        //* it needs to be initialized with the copy constructor using another shared_ptr to be aware of how many smart pointers own the resource
        std::shared_ptr<Resource> shared2 {shared1};
    }   //! second shared_ptr goes out of scope here but does not deallocate the resource it owned, because some other smart pointer is still pointing to it

    //? shared_ptrs have a special constructor that allows to pass an unique_ptr
    auto shared_smart_pointer {std::make_shared<Resource>(std::make_unique<Resource>())};

    return 0;
}   
//? shared1 goes out of scope here and will deallocate the dynamic resource because it is the last smart pointer that went out of scope and did point to the resource