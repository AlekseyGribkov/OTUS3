#include <stddef.h>
#include <iostream>

template<typename T>
class Vector
{
   private:
     size_t size;
     size_t cap;
     T* data;
   public:
     Vector();
     Vector(Vector&);
     Vector operator=(const Vector&);
     bool operator==(const Vector&);
     bool operator==(int);
     Vector(int i);
     size_t Capacity() const;
     size_t Size() const;
     T& operator [](int);
     ~Vector(void);
    public:
      void push_back(T);
      void clear();
      void create(const size_t &i);
      void remove(const size_t &i);
      void resize(const size_t &n);      
};

template<typename T>
Vector<T>::Vector(int i)
{
    /*
    size = i;
    data = new T[i];
    */

   std::cout << 111 << '\n';
   create(i);
}

template<typename T>
Vector<T>::Vector(){
    std::cout << 10 << '\n';
  create(1);
}

template<typename T>
Vector<T>::~Vector(void)
{
    if(this->data)
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
bool Vector<T>::operator==(int)
{  
   return false;
}

template<typename T>
Vector<T> Vector<T>::operator=(const Vector& a)
{
    size = a.size;
    for(int i = 0; i != a.size; ++i)
    {
        data[i] = a.data[i];        
    }
    return *this;
}

template<typename T>
bool Vector<T>::operator==(const Vector& a)
{
    if(this->size == a.size)
    {
        for(int i = 0; i < this->size; ++i)
        {
            if(this->data[i] != a.data[i])
            {
                return false;
            }
            return true;
        }
    }
    else
    {
        return false;
    }
}

template<typename T>
 Vector<T>::Vector(Vector& a)
{
   this->size = a.size;
   for(int i = 0; i < this->size; ++i)
   {
       this->data[i] = a.data[i];
   }
}


template<typename T>
void Vector<T>::create(const size_t &i)
{
    std::cout << 1024 << '\n';
    if(this->data){
        delete[] data;
    }
    this->size = 0;
    this->cap = i;
    data = new T[i];
}

template<typename T>
void Vector<T>::push_back(T val){
    T* newdata;
    if(size>cap){
        cap= cap*2;
        newdata = new T[cap];
        for(int i = 0; i < this->size; ++i){
            newdata[i] = data[i];            
        }
        delete[] data;
        data = newdata;
    }

    data[size] = val;
    size++;
}

template<typename T>
size_t Vector<T>::Capacity() const
{
    return cap;
}


template<typename T>
void Vector<T>::remove(const size_t &i)
{
    T* newdata = new T[cap];
    bool f = false;
    for(int j = 0; j< this->size; ++j)
    {
        if(j==i)
        {
            f = true;
        }

        if(f)
        {
            newdata[j-1] = this->data[j];            
        }
        else
        {
            newdata[j] = this->data[j];
        }

        this->size -=1;
        delete[] this->data;
        this->data = newdata;
        
    }
}

template<typename T>
void Vector<T>::resize(const size_t &n)
{
   T * newdata = new T[n];
   this->cap = n;
   this->size = n > this->size ? this->size : n;
   for(int i = 0; i < this->size; ++i){
       newdata[i] = this->data[i];
   }

   delete[] this->data;
   this->data = newdata;
}

template<typename T>
void Vector<T>::clear()
{
    delete[] this->data;
    this->size = 0;
    this->cap = 1;
    this->data = new T[1];
}


