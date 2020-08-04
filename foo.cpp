template<typename T>
class foo
{
private:
T data;
    /* data */
public:
    foo(T i);
    ~foo();
};

template<typename T>
foo<T>::foo(T i)
{
    std::cout << "start"<< '\n';
}
template<typename T>
foo<T>::~foo()
{
    std::cout << "stop"<< '\n';
}