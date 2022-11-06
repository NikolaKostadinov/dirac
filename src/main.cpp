#include "../include/dirac.h"

#include <cmath>
#include <iostream>

#define B   5.0f
#define N   10u
#define T   1600
#define DT  0.1f

int main()
{   
    Base*      x     = new Base(-B, N, B);
    WaveFunc1* psi   = new WaveFunc1(x)  ;
    Complex    probAmps[N]               ;

    for (uint32_t i = 0u; i < N; i++)
        probAmps[i] = Imag(1);

    psi->setValues(&probAmps[0]);
    psi->setNorm(1.0f)          ;
    psi->setMass(1.0f)          ;

    float expX   = psi->  eX();
    float devX   = psi->devX();

    std::cout << psi->string() << std::endl;
    std::cout << expX          << std::endl;
    std::cout << devX          << std::endl;

    std::cin.get();
    return 0;
}