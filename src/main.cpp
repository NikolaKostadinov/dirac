#include "../include/dirac.h"

#include <cmath>
#include <iostream>

#define B   500.0f
#define N   500u
#define T   1600
#define DT  0.1f

int main()
{   
    Base*      x     = new Base(-B,  N,  B);
    Basis2*    basis = new Basis2( x,   x );
    WaveFunc2* psi   = new WaveFunc2(basis);
    Complex    probAmps[N][N]              ;
    
    for (uint32_t i = 0u; i < N; i++)
        for (uint32_t j = 0u; j < N; j++)
            probAmps[i][j] = Imag( sqrt(i*i + j*j) );

    psi->setValues(&probAmps[0][0]);
    psi->setNorm(1.0f)             ;
    psi->setMass(1.0f)             ;

    std::cout << "\nindex\tnormed\t\tnot normed\ttotal not normed prob\n";

    for (int t = 0; t < T; t++)
    {
        psi->evolve(DT);
        std::cout << t                      << "\t";
        std::cout << psi->prob(0, 0, true ) << "\t";
        std::cout << psi->prob(0, 0, false) << "\t";
        std::cout << psi->prob(      false) << "\n";
    }

    std::cin.get();
    return 0;
}