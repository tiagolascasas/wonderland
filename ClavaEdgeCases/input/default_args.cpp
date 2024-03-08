#include <chrono>
#include <thread>

double foo(int a, int b, int c = 0, int d = 0)
{
    auto start = std::chrono::high_resolution_clock::now();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    return elapsed.count();
}

int main()
{
    foo(1, 2);
    foo(1, 2, 3);
    foo(1, 2, 3, 4);

    return 0;
}