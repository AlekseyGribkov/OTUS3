#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

#include <map>
#include <vector>
#include <string>
#include <iterator>

#include "checked.cpp"
#include "test.cpp"
#include "vector.cpp"

#include "foo.cpp"

#include "src/callocator.cpp"

/*
#include "mallocator.cpp"

using namespace std;
using namespace mmap_allocator_namespace;

//vector<int, mmap_allocator<int> > int_vec(1024, 0, mmap_allocator<int>());
*/

using namespace otus3;


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
    namespace std{
        std::ostream &operator<< (std::ostream &os, std::pair<std::string, int> const &c) {
                    return os << c.first << ": " << c.second;
        }
    }


    void allok(){

        
        std::map<std::string, int, std::less<std::string>,
        otus3::allocator<std::pair<const std::string, int>>> stuff;

        stuff["s1"] = 1;
        stuff["s2"] = 2;
        stuff["s3"] = 3;

        std::copy(stuff.begin(), stuff.end(),
        std::ostream_iterator<std::pair<std::string, int>>(std::cout, "\n"));
    }

    void allok2(){
        Vector<int> v2(10);
        v2.push_back(0);
        v2.push_back(1);
        v2.push_back(2);
        v2.push_back(3);
        v2.push_back(4);
        v2.push_back(5);
/*
        std::copy(0, 5, 
        std::ostream_iterator<int>(std::cout, "\n"));
        */
    }


int main(int argc, char** argv){

int t = 1;
    def<int> df(10);



    otus3::allocator<int> ca();
   //arr<int> f(10);
   //allok();
   Vector<int> v2(10);
   v2.push_back(5);

   std::cout << v2[0] << '\n';

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