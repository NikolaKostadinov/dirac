//#include "../include/dirac.h"
#include "../include/dmath.h"

#include <cmath>
#include <iostream>

#define B   5.0f
#define N   10u
#define T   1600
#define DT  0.1f

int main()
{   
    for (int i = 0; i < 10; i++) std::cout << expn((float) i) << std::endl;

    std::cin.get();
    return 0;
}