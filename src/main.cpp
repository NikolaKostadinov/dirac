#include <iostream>
#include "../include/dirac.h"

#define N 10000U

int main()
{   

    Base* x = new Base(-1.0F, 1.0F, 4U);
    Basis3* b = new Basis3(x, x, x);

    std::cout << b->zSize() << std::endl;

    std::cin.get();

    return 0;
}