#include <vector>
#include <string.h>
#include <iomanip>

#include "vectorization.cpp"

using namespace std;

#define TABLE_CELL_LEN 20

int64_t calculate_add_print(float *A, float *B, float *C, int size, int func)
{
    tick();
    add_vf(func)(A, B, C, size);
    auto dur = tock();
    return dur;
}

int64_t calculate_add_print(double *A, double *B, double *C, int size, int func)
{
    tick();
    add_vf_d(func)(A, B, C, size);
    auto dur = tock();
    return dur;
}

int main()
{
    int size = 16 * 1024 * 12;
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

    vector<string> names;
    vector<int> funcs;
    vector<int64_t> floatf_durations;
    vector<int64_t> doublef_durations;

    funcs.push_back(SSE2);
    funcs.push_back(SSE4_2);
    funcs.push_back(AVX2);
    funcs.push_back(AVX512);

    names.push_back(SSE2_STR);
    names.push_back(SSE4_2_STR);
    names.push_back(AVX2_STR);
    names.push_back(AVX512_STR);

    for (int i = 0; i < funcs.size(); i++)
    {
        floatf_durations.push_back(calculate_add_print(A, B, C, size, funcs.at(i)));
        doublef_durations.push_back(calculate_add_print(Ad, Bd, Cd, size, funcs.at(i)));
    }

    cout << "size of arrayes : " << size << endl;
    cout << setw(TABLE_CELL_LEN) << left << "Function" <<
            setw(TABLE_CELL_LEN) << left << "Float Time(us)" <<
            setw(TABLE_CELL_LEN) << left << "Double Time(us)" << endl;
    for (int i = 0; i < names.size(); i++)
    {
        cout << setw(TABLE_CELL_LEN) << left << names.at(i) <<
                setw(TABLE_CELL_LEN) << left << floatf_durations.at(i) <<
                setw(TABLE_CELL_LEN) << left << doublef_durations.at(i) << endl;
    }
}
// g++ -mavx2 -mavx512f main.cpp -o main  && ./main