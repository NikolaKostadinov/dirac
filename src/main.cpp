//#include "../include/dirac.h"

//#include <cmath>
#include <iostream>

#define B   5.0f
#define N   10u
#define T   1600
#define DT  0.1f

int main()
{
    //Base   x = Base(-B, N, B);
    //Basis2 b = Basis2(x, x);

    //std::cout << b(  0u,   0u).X << std::endl;
    //std::cout << b(  0u,   0u).Y << std::endl;
    //std::cout << b(N-1u, N-1u).X << std::endl;
    //std::cout << b(N-1u, N-1u).Y << std::endl;

    bool is1 = 4294967295u == -1u;
    bool is2 = 4294967294u == -2u;

    std::cout << is1 << std::endl;
    std::cout << is2 << std::endl;

    std::cin.get();
    return 0;
}