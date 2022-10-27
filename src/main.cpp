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
    Scalar2*     u     = new Scalar2(basis)  ;
    WaveFunc2*   psi   = new WaveFunc2(basis);

    float        potnVals[N][N];
    Complex      probAmps[N][N];
    for (uint32_t i = 0u; i < N; i++)
        for (uint32_t j = 0u; j < N; j++)
        {
            potnVals[i][j] = 1.0f              ;
            probAmps[i][j] = Complex(i*i + j*j);
        }

    psi->setMass(1.0F);
    psi->setNormValues(&probAmps[0][0]);

    u->setValues(&potnVals[0][0]);


    std::cout << psi->prob(0, 1) << std::endl     ;
    for (int t = 0; t < T; t++) psi->evolve(DT, u);
    std::cout << psi->prob(0, 1)  << std::endl    ;
    std::cout << psi->totalProb() << std::endl    ;

    std::cin.get();
    return 0;
}