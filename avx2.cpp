#include <immintrin.h> //AVX

void add_AVX2(float *A, float *B, float *C, int size) {
    for (int i = 0; i < size; i += 8) {
        __m256 inVec1 = _mm256_loadu_ps(&A[i]);
        __m256 inVec2 = _mm256_loadu_ps(&B[i]);
        __m256 outVec = _mm256_add_ps(inVec1, inVec2);
        _mm256_storeu_ps(&C[i], outVec);
    }
}
