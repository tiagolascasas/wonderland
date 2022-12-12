#include <chrono>
#include <iostream>
#include <cmath>
using namespace std::chrono;
using namespace std;

#define N1 1000
#define N2 100000
#define N3 500000
#define N4 1000000
#define N5 5000000

#pragma clava kernel
#pragma clava data kernel : [{auto : "auto" }, {auto : "auto" }]
template<unsigned int t_size> void foo(int X[t_size], int *res)
{
    int c = 0;
    for (int i = 0; i < 5000; i++)
        c += pow(i * 2, 2);
    *res = c;
}

int main()
{
    int res = 0;

    int* A = new int[N1];
    auto start = high_resolution_clock::now();
    foo<N1>(A, &res);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "{" << N1 << "} : " << duration.count() << endl;

    int B[N2] = {0};
    start = high_resolution_clock::now();
    foo<N2>(B, &res);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "{" << N2 << "} : " << duration.count() << endl;

    int C[N3] = {0};
    start = high_resolution_clock::now();
    foo<N3>(C, &res);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "{" << N3 << "} : " << duration.count() << endl;

    int D[N4] = {0};
    start = high_resolution_clock::now();
    foo<N4>(D, &res);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "{" << N4 << "} : " << duration.count() << endl;

    int *E = new int[N5];   // too big for the stack lol
    start = high_resolution_clock::now();
    foo<N5>(E, &res);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "{" << N5 << "} : " << duration.count() << endl;

    return 0;
}
