#include <cstdio>

#pragma oss task device(smp) in([1]num)
void reverse_print(double *num) {
	printf("FPGA num %lf\n", *num);
}

#pragma oss task device(fpga) in([1]src) out([1]dst)
void bar(const double *src, double *dst) {
	*dst += *src;
}

#pragma oss task device(fpga) in([1]src) out([1]dst)
void foo(const double *src, double *dst) {
	reverse_print(dst);
#pragma oss taskwait

	unsigned i;
	for (i = 0; i < 5; i++) {
		bar(src, dst);
		#pragma oss taskwait
	
		reverse_print(dst);
		#pragma oss taskwait
	}
}

int main() {
	double src = 88.77;
	double dst = 66.55;
	foo(&src, &dst);
#pragma oss taskwait
	printf("src %lf dst %lf\n", src, dst);
	return src != dst;
}
