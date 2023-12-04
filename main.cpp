#include <iostream>
#include <chrono>

#include "sse2.cpp"
#include "sse4_2.cpp"
#include "avx2.cpp"
#include "avx512.cpp"

using namespace std;

std::chrono::_V2::system_clock::time_point start;

void tick(){
    // Get the start time
    start = std::chrono::high_resolution_clock::now();
}

void tock(){
    // Get the end time
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate the duration
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "Time taken by function: "
              << duration.count() << "us" << std::endl;

}

void print_array(float *C, int size){
    for (int i = 0; i < 20; i++) {
        std::cout << C[i] << " ";
    }
    cout << "...." <<endl;
}

void set_default(float *arr, int size, float def_value = 0.0f){
    for (int i = 0; i < size; i++)
    {
        arr[i]=def_value;
    }
    
}

int main()
{
    int size = 16*1024*42;
    float A[size];
    float B[size];
    float C[size];

    set_default(A, size, 1.12f);
    set_default(B, size, 2.11f);

    
    cout << "Normal for loop :, A+B=C :" << endl;
    tick();
    for (int i = 0; i < size; i++)
    {
        C[i] = A[i] + B[i];
    }
    tock();
    print_array(C, size);
    cout << "________________________________________" << endl;

    cout << "SSE 2 , A+B=C :" << endl;
    tick();
    add_SSE2(A,B, C, size);
    tock();
    print_array(C, size);
    cout << "________________________________________" << endl;

    cout << "SSE 4.2 , A+B=C :" << endl;
    tick();
    add_SSE4_2(A,B, C, size);
    tock();
    print_array(C, size);
    cout << "________________________________________" << endl;

    cout << "AVX2 , A+B=C :" << endl;
    tick();
    add_SSE4_2(A,B, C, size);
    tock();
    print_array(C, size);
    cout << "________________________________________" << endl;

    cout << "AVX512 , A+B=C :" << endl;
    tick();
    add_SSE4_2(A,B, C, size);
    tock();
    print_array(C, size);
    cout << "________________________________________" << endl;



    return 0;
}
