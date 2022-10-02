#include "../include/dirac.h"
#include <iostream>

#define N 6U

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

    f->evolve(0.01F);

    std::cout << f->totalProb() << std::endl;
    std::cout << f->string() << std::endl;

    std::cin.get();
    return 0;
}