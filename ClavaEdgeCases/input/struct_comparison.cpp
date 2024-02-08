#include <iostream>

struct something_t
{
    int a;
    int b;
};

int main()
{
    struct something_t s;
    s.a = 1;
    s.b = 2;

    struct something_t t;
    t = s;

    std::cout << t.a << s.b << std::endl;
    return 0;
}