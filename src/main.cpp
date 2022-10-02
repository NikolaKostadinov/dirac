#include "../include/dirac.h"
#include <iostream>

int main()
{   
    Base* x = new Base(-1.0F, 4U, 1.0F);
    WaveFunc1* f = new WaveFunc1(x);

    Complex probAmp[4] = { Complex(1), Complex(0, 1), Complex(0, 1), Complex(1) };
    
    f->setValues(probAmp);
    f->normalize();
    std::cout << f->totalProb() << std::endl;

    std::cout << f->prob(0, 2) << std::endl;

    std::cin.get();
    return 0;
}