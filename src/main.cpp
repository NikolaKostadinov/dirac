#include "../include/dirac.h"

#include <cmath>
#include <iostream>

#define B   2.0f
#define N   4u
#define T   10000
#define DT  0.1f

int main()
{
    Base*        x  = new Base(-B, N, B);
    Basis2*   basis = new Basis2(x, x);
    WaveFunc2  psi  = WaveFunc2(basis);
    Complex probAmps[N][N];

    psi.setNorm(100.0f);
    psi.setMass(1.0f);
    psi.setValues(&probAmps[0][0]);

    for (int32_t i = 0u; i < N; i++)
        for (int32_t j = 0u; j < N; j++)
            probAmps[i][j] = exp(-i*i-j*j);

    std::cout << psi.string() << std::endl;
    for (int t = 0; t < T; t++)
    {
        std::cout << t << ": ";
        std::cout << psi.prob(false) << std::endl;
        psi.evolve();
    }
    std::cout << psi.string() << std::endl;

    std::cin.get();
    return 0;
}