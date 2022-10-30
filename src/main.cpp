#include "../include/dirac.h"
#include <cmath>
#include <iostream>

#define B   1.0f
#define N   4u
#define T   100
#define DT  10.0f

int main()
{   
    Base*      x     = new Base(-B, N, B)  ;
    Basis2*    basis = new Basis2(x, x)    ;
    WaveFunc2* psi   = new WaveFunc2(basis);
    Complex    probAmps[N][N]              ;
    
    for (uint32_t i = 0u; i < N; i++)
        for (uint32_t j = 0u; j < N; j++)
            probAmps[i][j] = Imag(sqrt(i*i + j*j));

    psi->setValues(&probAmps[0][0]);
    psi->setNorm(1.0f)             ;
    psi->setMass(1.0f)             ;

    std::cout << psi->prob()                 << std::endl;
    std::cout << psi->string()               << std::endl;
    std::cout << psi->probAmp(2, 2).string() << std::endl;
    std::cout << psi->prob(2, 2)             << std::endl;

    std::cin.get();
    return 0;
}