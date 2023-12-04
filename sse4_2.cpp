
#include <nmmintrin.h> // SSE4.2

void add_SSE4_2(float *A, float *B, float *C, int size) {
    for (int i = 0; i < size; i += 4) {
        __m128 inVec1 = _mm_loadu_ps(&A[i]);
        __m128 inVec2 = _mm_loadu_ps(&B[i]);
        __m128 outVec = _mm_add_ps(inVec1, inVec2);
        _mm_storeu_ps(&C[i], outVec);
    }
}
// int main() {
//     float A[] = {1.0f, 2.0f, 3.0f, 4.0f};
//     float B[] = {1.0f, 2.0f, 3.0f, 4.0f};
//     float C[4];

//     add_SSE4_2(A, B, C, 4);

//     for (int i = 0; i < 4; i++) {
//         std::cout << C[i] << " ";
//     }

//     return 0;
// }