#include "../include/dirac.h"
#include <iostream>

#define N 3U
#define T 10000
#define DT 0.01F

int main()
{   
    Base* x = new Base(-1, N, 1);
    Basis2* basis = new Basis2(x, x);
    WaveFunc2* psi = new WaveFunc2(basis);

    Complex probAmp[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            probAmp[j][i] = Complex(i, j);

    psi->setValues(&probAmp[0][0]);

    std::cout << psi->probAmp(1, 2).real() << std::endl;
    std::cout << psi->probAmp(1, 2).imag() << std::endl;

    std::cin.get();
    return 0;
}