#include <iostream>
#include "../include/dirac.h"

int main()
{   
    Base* x = new Base(-1.0F, 4U, 1.0F);
    WaveFunc1* f = new WaveFunc1(x);

    Complex probAmp[4] = { Complex(1), Complex(0, 1), Complex(0, 1), Complex(1) };
    f->setValues(probAmp);

    std::cout << f->string() << std::endl;

    std::cin.get();
    return 0;
}