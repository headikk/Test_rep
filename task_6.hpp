#pragma once

#include <bits/stdint-uintn.h>
#include <iostream>


template< int n > struct Fibonacci {
    static const uint64_t value = Fibonacci< n-1 >::value +  Fibonacci< n-2 >::value;
};

template<> struct Fibonacci< 1 > {
    static const uint64_t value = 1;
};

template<> struct Fibonacci< 0 > {
    static const uint64_t value = 0;
};

template<size_t N>
struct fibonacci : std::integral_constant<size_t, fibonacci<N-1>{} + fibonacci<N-2>{}> {};

template<> struct fibonacci<1> : std::integral_constant<size_t,1> {};
template<> struct fibonacci<0> : std::integral_constant<size_t,0> {};