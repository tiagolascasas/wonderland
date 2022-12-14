#include "OCL_Helpers.hpp"

cl::Context context;
cl::CommandQueue q;
cl::Program program;

extern int main_original();
cl::Kernel krnl_foo_N0;
cl::Kernel krnl_foo_N1;
cl::Kernel krnl_foo_N2;
cl::Kernel krnl_foo_N3;
cl::Kernel krnl_foo_N4;
cl::Kernel krnl_foo_N5;

int main(int argc, char *argv[]) {
   static std::string const platformName = "Xilinx";
   OCLH::getConfig(argv[1], platformName, context, q, program);
   krnl_foo_N0 = OCLH::getKernel("kernel_foo_N0", program);
   krnl_foo_N1 = OCLH::getKernel("kernel_foo_N1", program);
   krnl_foo_N2 = OCLH::getKernel("kernel_foo_N2", program);
   krnl_foo_N3 = OCLH::getKernel("kernel_foo_N3", program);
   krnl_foo_N4 = OCLH::getKernel("kernel_foo_N4", program);
   krnl_foo_N5 = OCLH::getKernel("kernel_foo_N5", program);
   return main_original();
}
