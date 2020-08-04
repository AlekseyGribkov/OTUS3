#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

#include "checked.cpp"
#include "test.cpp"
#include "vector.cpp"

#include "foo.cpp"
/*
#include "mallocator.cpp"

using namespace std;
using namespace mmap_allocator_namespace;

//vector<int, mmap_allocator<int> > int_vec(1024, 0, mmap_allocator<int>());
*/


template<typename T>
struct alloc : public std::allocator<T>
{
    
    T * allocate(std::size_t size, const void* hint = 0){
        fprintf(stderr, "Alloc %d bytes.\n", 
        static_cast<int>(size*sizeof(T)));
        std::allocator<T>::allocate(size, hint);
    }

    void deallocate(T * ptr, std::size_t size){
         fprintf(stderr, "Dealloc %d bytes (%p).\n", 
         static_cast<int>( size*sizeof(T)), ptr);
        return std::allocator<T>::deallocate(ptr, size);
    }

    template<typename _Tp1> struct rebind { typedef alloc<_Tp1> other;};
};

std::string value = "h";
auto lm = [val = std::move(value)](){
 
};







int main(int argc, char** argv){

   //foo<int> f;
   Vector<int> v2;

   //v2.push_back(10);
   
   //v2->push_back(10);
   //lm();
   //std::cout << value << '\n';
/*
   std::cout << __cplusplus << '\n';
   
   
    std::vector<dock, alloc<dock>> v1;
    

    for(int i = 0; i < 1000; ++i){
        dock d;
       v1.push_back(d);
    }


    for(auto &item : v1)
    std::cout << item << '\n';
    */

    

    //std::vector<int, a<int>> v(1000, 42);
    

   //_main();

    return 0;
}