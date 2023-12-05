
#include <immintrin.h> // AVX

#define AVX512 512
#define AVX512_STR "AVX512"
void add_AVX512(float *A, float *B, float *C, int size) {
    for (int i = 0; i < size; i += 16) {
        __m512 inVec1 = _mm512_loadu_ps(&A[i]);
        __m512 inVec2 = _mm512_loadu_ps(&B[i]);
        __m512 outVec = _mm512_add_ps(inVec1, inVec2);
        _mm512_storeu_ps(&C[i], outVec);
    }
}


void add_AVX512_d(double *A, double *B, double *C, int size) {
    for (int i = 0; i < size; i += 8) {
        __m512d inVec1 = _mm512_loadu_pd(&A[i]);
        __m512d inVec2 = _mm512_loadu_pd(&B[i]);
        __m512d outVec = _mm512_add_pd(inVec1, inVec2);
        _mm512_storeu_pd(&C[i], outVec);
    }
}

// int main() {
//     float A[] = {1.0f, 2.0f, 3.0f, 4.0f};
//     float B[] = {1.0f, 2.0f, 3.0f, 4.0f};
//     float C[4];

//     add_AVX512(A, B, C, 4);

//     for (int i = 0; i < 4; i++) {
//         std::cout << C[i] << " ";
//     }

//     return 0;
// }