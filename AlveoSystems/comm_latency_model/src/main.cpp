#include <chrono>
#include <iostream>
#include <cmath>
#include "OCL_Helpers.hpp"

using namespace std;
using namespace std::chrono;

#define N1 1000
#define N2 100000
#define N3 500000
#define N4 1000000
#define N5 5000000

extern cl::Kernel krnl_foo;
extern cl::CommandQueue q;
extern cl::Context context;

template<unsigned int t_size> void foo(int X[t_size], int *res) {
	cl::Buffer buffer_X(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_WRITE, sizeof(int[t_size]), X);
	krnl_foo.setArg(0, buffer_X);

	cl::Buffer buffer_res(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_WRITE, sizeof(int), res);
	krnl_foo.setArg(1, buffer_res);

	q.enqueueMigrateMemObjects({buffer_X, buffer_res}, 0 /* 0 means from host */);
	q.enqueueTask(krnl_foo);
	q.finish();
	q.enqueueMigrateMemObjects({buffer_X, buffer_res}, CL_MIGRATE_MEM_OBJECT_HOST);
	q.finish();
}

int main_original() {
	srand(time(0));
	int res = 0;

	int A[N1] = { rand() };
	auto start = high_resolution_clock::now();
	foo<N1>(A, &res);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "{" << N1 << "} : " << duration.count() << endl;

	int B[N2] = { rand() };
	start = high_resolution_clock::now();
	foo<N2>(B, &res);
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "{" << N2 << "} : " << duration.count() << endl;

	int C[N3] = { rand() };
	start = high_resolution_clock::now();
	foo<N3>(C, &res);
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "{" << N3 << "} : " << duration.count() << endl;

	int D[N4] = { rand() };
	start = high_resolution_clock::now();
	foo<N4>(D, &res);
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "{" << N4 << "} : " << duration.count() << endl;

	int *E = new int[N5];
	start = high_resolution_clock::now();
	foo<N5>(E, &res);
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "{" << N5 << "} : " << duration.count() << endl;

	return 0;
}
