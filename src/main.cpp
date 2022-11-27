#include "../include/dirac.h"

#include <cmath>
#include <iostream>

#define B   5.0f
#define N   10u
#define T   1600
#define DT  0.1f

int main()
{
    Base   x = Base(-B, N, B);
    Basis2 b = Basis2(x, x);

    std::cout << b(  0u,   0u).X << std::endl;
    std::cout << b(  0u,   0u).Y << std::endl;
    std::cout << b(N-1u, N-1u).X << std::endl;
    std::cout << b(N-1u, N-1u).Y << std::endl;

    std::cin.get();
    return 0;
}