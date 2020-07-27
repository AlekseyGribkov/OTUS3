#include <iosfwd>
#include <cstddef>
#include <stdint.h>

typedef unsigned long WORD;

inline std::size_t align(std::size_t n){
    return (n + sizeof(WORD) - 1) & ~(sizeof(WORD) - 1);
}