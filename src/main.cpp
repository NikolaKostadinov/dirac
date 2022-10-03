#include "../include/dirac.h"
#include <iostream>

#define N 4U
#define T 100000
#define DT 0.01F

int main()
{   
    Base* x = new Base(-1, N, 1);
    Basis2* basis = new Basis2(x, x);
    WaveFunc2* psi = new WaveFunc2(basis);

    Complex probAmp[N][N] = { { Complex(001), Complex(001), Complex(001), Complex(001) },
                              { Complex(001), Complex(100), Complex(100), Complex(001) },
                              { Complex(001), Complex(100), Complex(100), Complex(001) },
                              { Complex(001), Complex(001), Complex(001), Complex(001) } };

    psi->setValues(&probAmp[0][0]);
    psi->normalize();

    std::cout << psi->string() << std::endl << std::endl;

    for (int i = 0; i < T; i++) psi->evolve(DT);

    std::cout << psi->string() << std::endl;

    std::cin.get();
    return 0;
}