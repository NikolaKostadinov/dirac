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

    Complex probAmp[N][N] = { { Complex(1), Complex(1), Complex(1), Complex(1) }, 
                              { Complex(1), Complex(100), Complex(100), Complex(1) },
                              { Complex(1), Complex(100), Complex(100), Complex(1) },
                              { Complex(1), Complex(1), Complex(1), Complex(1) } };

    psi->setValues(&probAmp[0][0]);
    psi->normalize();

    for (int i = 0; i < N; i++)
    {   
        for (int j = 0; j < N; j++)
            std::cout << psi->probAmp(i, j).string() << "  ";
        std::cout << std::endl;
    }

    std::cout << std::endl;

    for (int i = 0; i < T; i++)
        psi->evolve(DT);

    for (int i = 0; i < N; i++)
    {   
        for (int j = 0; j < N; j++)
            std::cout << psi->probAmp(i, j).string() << "  ";
        std::cout << std::endl;
    }

    std::cin.get();
    return 0;
}