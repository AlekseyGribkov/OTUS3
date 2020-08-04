#include "vector.h"

template<typename T>
Vector<T>::Vector(int i)
{
    /*
    size = i;
    data = new T[i];
    */
   create(i);
}

template<typename T>
Vector<T>::~Vector(void)
{
    delete []data;
}

template<typename T>
size_t Vector<T>::Size(void) const{
    return size;
}

template<typename T>
T& Vector<T>::operator[](int i)
{
    return data[i];
}

template<typename T>
Vector<T> Vector<T>::operator=(const Vector& a)
{
    size = a.size;
    for(int i = ; i != a.size; ++i)
    {
        data[i] = a.data[i];        
    }
    return *this;
}


template<typename T>
void Vector<T>::create(const size_t &i)
{
    if(thi->data){
        delete[] data;
    }
}