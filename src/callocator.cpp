#ifndef ALLOCATOR_H_INC_
#define ALLOCATOR_H_INC_

#include <stdlib.h>
#include <new>
#include <limits>

namespace otus3
{
    template<typename T>
    struct  allocator
    {
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;
        typedef T* pointer;
        typedef const T* const_pointer;
        typedef T& reference;
        typedef const T& const_reference;
        typedef T value_type;

        template <typename U> struct  rebind {typedef allocator<U> other;};
        allocator() throw(){}
        allocator(const allocator&) throw(){}

        template<typename U> allocator(const allocator<U> & ) throw(){}
        ~allocator() throw(){}

        pointer address(reference x) const {return &x;}
        const_pointer address(const_reference x) const {return &x;}

        pointer allocate(size_type s, void const * = 0){
            if(0 == s) return NULL;
            pointer temp = (pointer)malloc(s * sizeof(T));
            if(temp ==  NULL) throw std::bad_alloc(); 
            std::cout << s << " allocate" << "\n";           
            return temp;
        }

        void deallocate(pointer p, size_type){
            std::cout << " deallocate" << "\n";  
            free(p);
        }

        size_type max_size() const throw(){
            return std::numeric_limits<size_t>::max()/sizeof(T);
        }


        void construct(pointer p, const T& val){
            new ((void *)p) T(val);
        }


        void destroy(pointer p){
            p->~T();
        }
    };
    
}

#endif