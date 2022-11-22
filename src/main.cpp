#include "../include/dirac.h"

#include <cmath>
#include <iostream>

#define B   5.0f
#define N   10u
#define T   1600
#define DT  0.1f

int main()
{   
    Complex x = Complex(1, 2);
    Complex y = Complex(4, 5);
    Complex z = x + y;

    std::cin.get();
    return 0;
}