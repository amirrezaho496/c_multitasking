#include "sse2.cpp"
#include "sse4_2.cpp"
#include "avx2.cpp"
#include "avx512.cpp"
#include "utilities.cpp"


int main()
{
    int size = 16*1024*12;
    float A[size];
    float B[size];
    float C[size];

    double Ad[size];
    double Bd[size];
    double Cd[size];

    set_default(A, size, 1.12f);
    set_default(B, size, 2.11f);

    set_default(Ad, size, 1.12);
    set_default(Bd, size, 2.11);

    cout << "size of arrayes : " << size << endl;
    cout << "Normal for loop :, A+B=C :" << endl;
    cout << "float:" << endl;
    tick();
    add(A,B, C, size);
    tock();
    print_array(C, size);
    cout <<endl<<"double:" << endl;
    tick();
    add(Ad,Bd, Cd, size);
    tock();
    print_array(Cd, size);
    cout << "________________________________________" << endl<<endl;

    cout << "SSE 2 A+B=C :" << endl;
    cout << "float:" << endl;
    tick();
    add_SSE2(A,B, C, size);
    tock();
    print_array(Cd, size);
    cout <<endl<<"double:" << endl;
    tick();
    add_SSE2_d(Ad,Bd, Cd, size);
    tock();
    print_array(Cd, size);
    cout << "________________________________________" << endl<<endl;

    cout << "SSE 4.2 , A+B=C :" << endl;
    cout << "float:" << endl;
    tick();
    add_SSE4_2(A,B, C, size);
    tock();
    print_array(Cd, size);
    cout <<endl<<"double:" << endl;
    tick();
    add_SSE4_2_d(Ad,Bd, Cd, size);
    tock();
    print_array(Cd, size);
    cout << "________________________________________" << endl<<endl;

    cout << "AVX2 , A+B=C :" << endl;
    cout << "float:" << endl;
    tick();
    add_AVX2(A,B, C, size);
    tock();
    print_array(Cd, size);
    cout <<endl<<"double:" << endl;
    tick();
    add_AVX2_d(Ad,Bd, Cd, size);
    tock();
    print_array(Cd, size);
    cout << "________________________________________" << endl<<endl;

    cout << "AVX512 , A+B=C :" << endl;
    cout << "float:" << endl;
    tick();
    add_AVX512(A,B, C, size);
    tock();
    print_array(Cd, size);
    cout <<endl<<"double:" << endl;
    tick();
    add_AVX512_d(Ad,Bd, Cd, size);
    tock();
    print_array(Cd, size);
    cout << "________________________________________" << endl<<endl;



    return 0;
}


//g++ -mavx2 -mavx512f main.cpp -o main  && ./main 