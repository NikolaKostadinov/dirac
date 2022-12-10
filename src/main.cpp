#include "../include/dirac.h"

#include <cmath>
#include <iostream>

#define B   5.0f
#define N   10u
#define T   1600
#define DT  0.1f

int main()
{
    Base         x = Base(-B, N, B);
    Basis2   basis = Basis2(x, x);
    WaveFunc2  psi = WaveFunc2(basis);
    Complex probAmps[N][N];

    psi.setNorm(1.0f);
    psi.setMass(1.0f);
    psi.setValues(&probAmps[0][0]);

    for (int32_t i = 0u; i < N; i++)
        for (int32_t j = 0u; j < N; j++)
            probAmps[i][j] = i*i + j*j;

    std::cout << psi.prob(N-1u, N-1u) << std::endl;
    //for (int t = 0; t < T; t++) psi.evolve();
    //std::cout << psi.prob(4, 4) << std::endl;

    std::cin.get();
    return 0;
}