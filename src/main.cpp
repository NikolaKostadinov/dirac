#include "../include/dirac.h"
#include <cmath>
#include <iostream>

#define N   200u
#define T   16
#define DT  0.01F

int main()
{   
    Base*      x     = new Base(-1, N, 1)  ;
    Basis2*    basis = new Basis2(x, x)    ;
    WaveFunc2* psi   = new WaveFunc2(basis);

    Complex probAmp[N][N];
    for (uint32_t i = 0U; i < N; i++)
        for (uint32_t j = 0U; j < N; j++)
            probAmp[i][j] = Complex(cos(i), sin(j));

    psi->setMass(1.0F);
    psi->setNormValues(&probAmp[0][0]);

    std::cout << psi->string() << std::endl << std::endl;

    for (int i = 0; i < T; i++) psi->evolveFree(DT);

    std::cout << psi->string() << std::endl;

    std::cin.get();
    return 0;
}