#include <stddef.h>

template<typename T>
class Vector
{
   private:
     size_t size;
     int cap;
     T* data;
   public:
     Vector(Vector&);
     Vector operator=(const Vector&);
     Vector operator==(const Vector&);
     bool operator==(int);
     Vector(int=1);
     int Capacity() const;
     size_t Size() const;
     T& operator [](int);
     ~Vector(void);
    public:
      void push_bakc(T);
      void clear();
      void create(const size_t &i);
      void remove(const int &i);
      void resize(const int &n);      
};