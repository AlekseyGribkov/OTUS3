#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

#include "checked.cpp"
#include "test.cpp"
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

template <typename T> class a : public std::allocator<T> {
public:
    T* allocate(std::size_t n, const void* hint = 0) const {
        std::cout << "yo!" << '\n';
        return new T[n];
    }

    void deallocate(T * ptr, std::size_t size){
         std::cout << " 3" + size << '\n';
        delete[] ptr;
    }
    
    template <typename U> struct rebind
    {
        typedef a<U> other;
    };
    
};

int main(int argc, char** argv){

   //lm();
   //std::cout << value << '\n';

   
   
   
    std::vector<int, alloc<int>> v1;
    v1.push_back(10);
    v1.push_back(20);
    //v1.push_back(30);
    v1.push_back(40);


    for(auto &item : v1)
    std::cout << item << '\n';
    
    

    //std::vector<int, a<int>> v(1000, 42);
    

   //_main();

    return 0;
}