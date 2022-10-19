#include "../include/dirac.h"
#include <cmath>
#include <iostream>

#define N   20u
#define T   16
#define DT  0.01F

int main()
{   
    Base*      x     = new Base(-1, N, 1)  ;
    /*Basis2*    basis = new Basis2(x, x)    ;
    WaveFunc2* psi   = new WaveFunc2(basis);

    Complex probAmp[N][N];
    for (uint32_t i = 0U; i < N; i++)
        for (uint32_t j = 0U; j < N; j++)
            probAmp[i][j] = Complex(cos(i), sin(j));

    psi->setMass(1.0F);
    psi->setNormValues(&probAmp[0][0]);

    std::cout << psi->string() << std::endl << std::endl;

    for (int i = 0; i < T; i++) psi->evolveFree(DT);

    std::cout << psi->string() << std::endl;*/

    Complex      probAmps             [N][N][N] ;
    Basis3*      basis    = new Basis3(x, x, x) ;
    WaveFunc3*   psi      = new WaveFunc3(basis);

    for (uint32_t i = 0u; i < N; i++)
        for (uint32_t j = 0u; j < N; j++)
            for (uint32_t k = 0u; k < N; k++)
                probAmps[i][j][k] = Complex(i * j * k);

    psi->setMass(1.0F);
    psi->setValues(&probAmps[0][0][0]);

    std::cout << psi->prob(10, 10, 10) << std::endl;

    std::cin.get();
    return 0;
}