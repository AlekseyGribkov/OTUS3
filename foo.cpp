#include <stddef.h>

template<typename T>
class arr
{
private:
   T* data{nullptr};
   size_t size{0};
   size_t cap{0};
public:
    arr(size_t i = 1);
    ~arr();
    arr(arr&);
    void create(const size_t &i);

};

template<typename T>
arr<T>::arr(size_t i)
{
    std::cout << i << '\n';
    create(i);
}
template<typename T>
arr<T>::~arr(void)
{
    std::cout << "stop"<< '\n';
    if(this->data != nullptr)delete[] data;
}

template<typename T>
void arr<T>::create(const size_t &i)
{
    if(this->data != nullptr) delete[] data;
    this->size = 0;
    this->cap = i;
    data = new T[i];
}