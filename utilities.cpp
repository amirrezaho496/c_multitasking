#include <iostream>
#include <chrono>


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
    int show = 4;
    for (int i = 0; i < show; i++) {
        std::cout << C[i] << " ";
    }
    cout << " .... ";
    for (int i = size-show; i < size; i++) {
        std::cout << C[i] << " ";
    }
    cout << endl;
}
void print_array(double *C, int size){
    int show = 4;
    for (int i = 0; i < show; i++) {
        std::cout << C[i] << " ";
    }
    cout << " .... ";
    for (int i = size-show; i < size; i++) {
        std::cout << C[i] << " ";
    }
    cout << endl;
}

void set_default(float *arr, int size, float def_value = 0.0f){
    for (int i = 0; i < size; i++)
    {
        arr[i]=def_value;
    }
    
}

void set_default(double *arr, int size, double def_value = 0.0f){
    for (int i = 0; i < size; i++)
    {
        arr[i]=def_value;
    }
    
}


void add(float *A, float *B, float *C, int size){
    for (int i = 0; i < size; i++)
    {
        C[i] = A[i] + B[i];
    }
}

void add(double *A, double *B, double *C, int size){
    for (int i = 0; i < size; i++)
    {
        C[i] = A[i] + B[i];
    }
}