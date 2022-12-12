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

extern cl::Kernel krnl_foo_N0;
extern cl::Kernel krnl_foo_N1;
extern cl::Kernel krnl_foo_N2;
extern cl::Kernel krnl_foo_N3;
extern cl::Kernel krnl_foo_N4;
extern cl::Kernel krnl_foo_N5;
extern cl::CommandQueue q;
extern cl::Context context;

void foo_N0(int res[1]) {
	cl::Buffer buffer_res(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_WRITE, sizeof(int[1]), res);
	krnl_foo_N0.setArg(0, buffer_res);

	q.enqueueMigrateMemObjects({buffer_res}, 0 /* 0 means from host */);
	q.enqueueTask(krnl_foo_N0);
	q.finish();
	q.enqueueMigrateMemObjects({buffer_res}, CL_MIGRATE_MEM_OBJECT_HOST);
	q.finish();
}

void foo_N1(int X[N1], int res[1]) {
	cl::Buffer buffer_X(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_WRITE, sizeof(int[N1]), X);
	krnl_foo_N1.setArg(0, buffer_X);

	cl::Buffer buffer_res(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_WRITE, sizeof(int[1]), res);
	krnl_foo_N1.setArg(1, buffer_res);

	q.enqueueMigrateMemObjects({buffer_X, buffer_res}, 0 /* 0 means from host */);
	q.enqueueTask(krnl_foo_N1);
	q.finish();
	q.enqueueMigrateMemObjects({buffer_X, buffer_res}, CL_MIGRATE_MEM_OBJECT_HOST);
	q.finish();
}

void foo_N2(int X[N2], int res[1]) {
	cl::Buffer buffer_X(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_WRITE, sizeof(int[N2]), X);
	krnl_foo_N2.setArg(0, buffer_X);

	cl::Buffer buffer_res(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_WRITE, sizeof(int[1]), res);
	krnl_foo_N2.setArg(1, buffer_res);

	q.enqueueMigrateMemObjects({buffer_X, buffer_res}, 0 /* 0 means from host */);
	q.enqueueTask(krnl_foo_N2);
	q.finish();
	q.enqueueMigrateMemObjects({buffer_X, buffer_res}, CL_MIGRATE_MEM_OBJECT_HOST);
	q.finish();
}

void foo_N3(int X[N3], int res[1]) {
	cl::Buffer buffer_X(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_WRITE, sizeof(int[N3]), X);
	krnl_foo_N3.setArg(0, buffer_X);

	cl::Buffer buffer_res(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_WRITE, sizeof(int[1]), res);
	krnl_foo_N3.setArg(1, buffer_res);

	q.enqueueMigrateMemObjects({buffer_X, buffer_res}, 0 /* 0 means from host */);
	q.enqueueTask(krnl_foo_N3);
	q.finish();
	q.enqueueMigrateMemObjects({buffer_X, buffer_res}, CL_MIGRATE_MEM_OBJECT_HOST);
	q.finish();
}

void foo_N4(int X[N4], int res[1]) {
	cl::Buffer buffer_X(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_WRITE, sizeof(int[N4]), X);
	krnl_foo_N4.setArg(0, buffer_X);

	cl::Buffer buffer_res(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_WRITE, sizeof(int[1]), res);
	krnl_foo_N4.setArg(1, buffer_res);

	q.enqueueMigrateMemObjects({buffer_X, buffer_res}, 0 /* 0 means from host */);
	q.enqueueTask(krnl_foo_N4);
	q.finish();
	q.enqueueMigrateMemObjects({buffer_X, buffer_res}, CL_MIGRATE_MEM_OBJECT_HOST);
	q.finish();
}

void foo_N5(int X[N5], int res[1]) {
	cl::Buffer buffer_X(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_WRITE, sizeof(int[N5]), X);
	krnl_foo_N5.setArg(0, buffer_X);

	cl::Buffer buffer_res(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_WRITE, sizeof(int[1]), res);
	krnl_foo_N5.setArg(1, buffer_res);

	q.enqueueMigrateMemObjects({buffer_X, buffer_res}, 0 /* 0 means from host */);
	q.enqueueTask(krnl_foo_N5);
	q.finish();
	q.enqueueMigrateMemObjects({buffer_X, buffer_res}, CL_MIGRATE_MEM_OBJECT_HOST);
	q.finish();
}

int main_original() {
	srand(time(0));
	int res[1] = {0};

	auto start = high_resolution_clock::now();
	foo_N0(res);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "{" << 0 << "} : " << duration.count() << endl;

	int A[N1] = { rand() };
	start = high_resolution_clock::now();
	foo_N1(A, res);
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "{" << N1 << "} : " << duration.count() << endl;

	int B[N2] = { rand() };
	start = high_resolution_clock::now();
	foo_N2(B, res);
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "{" << N2 << "} : " << duration.count() << endl;

	int C[N3] = { rand() };
	start = high_resolution_clock::now();
	foo_N3(C, res);
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "{" << N3 << "} : " << duration.count() << endl;

	int D[N4] = { rand() };
	start = high_resolution_clock::now();
	foo_N4(D, res);
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "{" << N4 << "} : " << duration.count() << endl;

	int *E = new int[N5];
	start = high_resolution_clock::now();
	foo_N5(E, res);
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "{" << N5 << "} : " << duration.count() << endl;

	return 0;
}
