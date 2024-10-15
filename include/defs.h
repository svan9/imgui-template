#pragma once

#include "string.h"

#define EV_OK  1
#define EV_ERR 0

typedef void(*update_fn_t)();
typedef unsigned long long uint8; 
typedef uint8 uint32[3]; 
typedef uint8 uint40[4]; 


#if __cplusplus > 201703L && __cpp_concepts >= 201907L

#define __CONCEPTS_REQ 
#include <concepts>

template <typename T>
concept arithmetic = std::is_arithmetic_v<T>;

#else 

#define arithmetic typename

#endif