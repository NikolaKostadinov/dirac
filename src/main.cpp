#include <iostream>
#include "../include/dirac.h"

int main()
{   
    Base* x = new Base(-1.0F, 4U, 1.0F);
    WaveFunc1* f = new WaveFunc1(x);

    Complex probAmp[4] = { Complex(1), Complex(0, 1), Complex(0, 1), Complex(1) };
    
    f->setValues(probAmp);
    f->normalize(100);
    std::cout << f->totalProb() << std::endl;

    for (int i = 0; i < 4; i++)
        std::cout << probAmp[i].string() << std::endl;

    std::cin.get();
    return 0;
}