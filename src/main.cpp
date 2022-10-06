#include "../include/dirac.h"
#include <cmath>
#include <iostream>

#define N 200U
#define T 1665
#define DT 0.01F

int main()
{   
    Base* x = new Base(-1, N, 1);
    Basis2* basis = new Basis2(x, x);
    WaveFunc2* psi = new WaveFunc2(basis);

    Complex probAmp[N][N];
    for (unsigned int i = 0U; i < N; i++)
        for (unsigned int j = 0U; j < N; j++)
            probAmp[i][j] = Complex(cos(i), sin(j));

    psi->setValues(&probAmp[0][0]);
    psi->normalize();

    std::cout << psi->string() << std::endl << std::endl;

    for (int i = 0; i < T; i++) psi->evolve(DT);

    std::cout << psi->string() << std::endl;

    std::cin.get();
    return 0;
}