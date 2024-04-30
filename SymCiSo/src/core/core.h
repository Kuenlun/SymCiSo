#pragma once

#include <vector>

// BOOST_STATIC_ASSERT
#define STATIC_ASSERT(...) static_assert(__VA_ARGS__, #__VA_ARGS__)

#define ASSERT(...) assert(__VA_ARGS__, #__VA_ARGS__)

namespace SymCiSo
{
    
    template <class T>
    void remove_ptr_from_vector(std::vector<T*>& vec, const T* const ptr)
    {
        vec.erase(std::remove(vec.begin(), vec.end(), ptr), vec.end());
    }

} // namespace SymCiSo
