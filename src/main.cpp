#include "../include/dirac.h"

#include <cmath>
#include <iostream>

#define B   100.0f
#define N   100u
#define T   10
#define DT  10.0f

int main()
{   
    Base*      x     = new Base(-B, N, B)  ;
    Basis2*    basis = new Basis2(x, x)    ;
    WaveFunc2* psi   = new WaveFunc2(basis);
    Complex    probAmps[N][N]              ;
    
    for (uint32_t i = 0u; i < N; i++)
        for (uint32_t j = 0u; j < N; j++)
            probAmps[i][j] = Imag( sqrt(i*i + j*j) );

    psi->setValues(&probAmps[0][0]);
    psi->setNorm(1.0f)             ;
    psi->setMass(1.0f)             ;

    for (int t = 0; t < T; t++)
    {
        psi->evolve();
        std::cout << psi->prob(0, 0, true ) << "\t";
        std::cout << psi->prob(0, 0, false) << "\n";
    }

    //std::cin.get();
    return 0;
}