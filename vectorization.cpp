
#include "sse2.cpp"
#include "sse4_2.cpp"
#include "avx2.cpp"
#include "avx512.cpp"
#include "utilities.cpp"
#include "strings.h"

typedef void(*add_vectorfunction)(float *A, float *B, float *C, int size);
typedef void(*add_vectorfunction_d)(double *A, double *B, double *C, int size);


add_vectorfunction add_vf(int function_name){
    switch (function_name)
    {
    case SSE2:
        return add_SSE2;
    case SSE4_2:
        return add_SSE4_2;
    case AVX2:
        return add_AVX2;
    case AVX512:
        return add_AVX512;
    default:
        return add;
    }
} 

add_vectorfunction_d add_vf_d(int function_name){
    switch (function_name)
    {
    case SSE2:
        return add_SSE2_d;
    case SSE4_2:
        return add_SSE4_2_d;
    case AVX2:
        return add_AVX2_d;
    case AVX512:
        return add_AVX512_d;
    default:
        return add;
    }
} 