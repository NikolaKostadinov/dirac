#include <iostream>
#include "../include/dirac.h"

#define N 10000U

int main()
{   
    Base* x = new Base(-1.0F, 1.0F, 4U);
    WaveFunc1* f = new WaveFunc1(x);
    Complex probAmp[4] = { Complex(1), Complex(0, 1), Complex(0, 1), Complex(1) };
    f->setValues(probAmp);

    std::cout << f->value(2).mod() << std::endl;

    std::cin.get();
    return 0;
}