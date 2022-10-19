#include "../include/dirac.h"
#include <cmath>
#include <iostream>

#define N   20u
#define T   160
#define DT  0.01F

int main()
{   
    Base*        x     = new Base(-1, N, 1)  ;
    Basis3*      basis = new Basis3(x, x, x) ;
    WaveFunc3*   psi   = new WaveFunc3(basis);

    Complex      probAmps[N][N][N];
    for (uint32_t i = 0u; i < N; i++)
        for (uint32_t j = 0u; j < N; j++)
            for (uint32_t k = 0u; k < N; k++)
                probAmps[i][j][k] = Complex(i * j * k);

    psi->setMass(1.0F);
    psi->setNormValues(&probAmps[0][0][0]);

    std::cout << psi->prob(10, 10, 10) << std::endl;
    for (int t = 0; t < T; t++) psi->evolveFree(DT);
    std::cout << psi->prob(10, 10, 10) << std::endl;

    std::cin.get();
    return 0;
}