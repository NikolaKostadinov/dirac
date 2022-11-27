#include "../include/dirac.h"

#include <cmath>
#include <iostream>

#define B   5.0f
#define N   10u
#define T   1600
#define DT  0.1f

int main()
{
    Base x = Base(-B, N, B);

    std::cout << x(    0u) << std::endl;
    std::cout << x(N - 1u) << std::endl;

    std::cin.get();
    return 0;
}