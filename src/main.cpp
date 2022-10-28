#include "../include/dirac.h"
#include <cmath>
#include <iostream>

#define B   100.0f
#define N   4u
#define T   100
#define DT  10.0f

int main()
{   
    Base*       x     = new Base(-B, N, B);
    WaveFunc1*  psi   = new WaveFunc1(x)  ;
    Complex     probAmps[N]               ;
    
    for (uint32_t i = 0u; i < N; i++)
        probAmps[i] = Complex(i, i);

    psi->setValues(&probAmps[0]);
    psi->setNorm(1.0f);
    psi->setMass(1.0f);

    std::cout << psi->prob()   << std::endl;
    std::cout << psi->string() << std::endl;

    std::cin.get();
    return 0;
}