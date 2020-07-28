#include <iosfwd>
#include <cstddef>
#include <stdint.h>
#include <unistd.h>

typedef unsigned long WORD;

inline std::size_t align(std::size_t n){
    return (n + sizeof(WORD) - 1) & ~(sizeof(WORD) - 1);
}

template<typename T>
inline std::size_t alloSize(std::size_t size){
  return size + sizeof(T) - sizeof(std::declval<T>());
}