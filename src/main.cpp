#include "../include/dirac.h"
#include <iostream>

#define N 6U
#define T 100
#define DT 0.01F

int main()
{   
    Base* x = new Base(-1.0F, N, 1.0F);
    WaveFunc1* f = new WaveFunc1(x);

    Complex probAmp[N] = {
        Complex(1),
        Complex(1),
        Complex(100),
        Complex(100),
        Complex(1),
        Complex(1)
    };
    
    f->setValues(probAmp);
    f->normalize();

    std::cout << f->totalProb() << std::endl;
    std::cout << f->string() << std::endl;

    for (int i = 0; i < T; i++)
        f->evolve(DT);

    std::cout << f->totalProb() << std::endl;
    std::cout << f->string() << std::endl;

    std::cin.get();
    return 0;
}