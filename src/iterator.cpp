//#include "vector.cpp"
#include <iterator>

template<typename T>
 struct iterator
    {
        using value_type = T ;
        using reference = T& ;
        using pointer = T* ;
        using difference_type = std::ptrdiff_t ;
        using iterator_category	= std::forward_iterator_tag ;

        reference operator* () { return *curr ; }
        // pointer operator& () { return &**this ; }
        pointer operator-> () { return &**this ; } // *** EDIT

        iterator& operator++ () { ++curr ; return *this ; }
        iterator operator++ (int) { const auto temp(*this) ; ++*this ; return temp ; }

        bool operator== ( const iterator& that ) const { return curr == that.curr ; }
        bool operator!= ( const iterator& that ) const { return !(*this==that) ; }

        iterator& next_row()
        {
            if( std::distance( curr, end ) >= difference_type(ncols) ) std::advance( curr, ncols ) ;
            else curr = end ;
            return *this ;
        }

        typename std::vector<T>::iterator curr ;
        typename std::vector<T>::iterator end ;
        std::size_t ncols ;

    };

