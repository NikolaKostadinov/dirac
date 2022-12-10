#include "../include/dirac.h"

#include <cmath>
#include <iostream>

#define B   5.0f
#define N   10u
#define T   1600
#define DT  0.1f

int main()
{
    Base    x = Base(-B, N, B);
    Scalar1 f = Scalar1(x);
    float   values[N];

    for (int32_t i = 0u; i < N; i++) values[i] = i+1;
    
    f.setValues(&values[0]);
    
    std::cout << f.value(  2u, true) << std::endl;
    std::cout << f.value( -1u, true) << std::endl;
    std::cout << f.value( -2u, true) << std::endl;
    std::cout << f.value(N   , true) << std::endl;
    std::cout << f.value(N-1u, true) << std::endl;
    std::cout << f.value(N+1u, true) << std::endl;

    std::cin.get();
    return 0;
}