#include "../include/dirac.h"
#include <cmath>
#include <iostream>

#define N   4u
#define T   10
#define DT  0.1F

int main()
{   
    Base*        x     = new Base(-1, N, 1)  ;
    Basis2*      basis = new Basis2(x, x)    ;
    WaveFunc2*   psi   = new WaveFunc2(basis);

    Complex      probAmps[N][N];
    for (uint32_t i = 0u; i < N; i++)
        for (uint32_t j = 0u; j < N; j++)
            probAmps[i][j] = Complex(i*i + j*j);

    psi->setMass(1.0F);
    psi->setNormValues(&probAmps[0][0]);

    Scalar2* nullPtntl = new Scalar2(basis);

    for (uint32_t i = 0u; i < N; i++)
        for (uint32_t j = 0u; j < N; j++)
            *nullPtntl->address(i, j) = 0.0f;

    std::cout << psi->prob(0, 1) << std::endl;
    for (int t = 0; t < T; t++) psi->evolve(DT, nullPtntl);
    std::cout << psi->prob(0, 1) << std::endl;

    std::cin.get();
    return 0;
}