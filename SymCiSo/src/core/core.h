#pragma once

// BOOST_STATIC_ASSERT
#define STATIC_ASSERT(...) static_assert(__VA_ARGS__, #__VA_ARGS__)

#define ASSERT(...) assert(__VA_ARGS__, #__VA_ARGS__)

namespace SymCiSo
{

} // namespace SymCiSo
