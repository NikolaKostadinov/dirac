#include <iostream>
#include "../include/dirac.h"

#define N 10

int main()
{
    Basis1<N>* basis = new Basis1<N>;
    Field1<float, N> field(basis);

    std::cin.get();
    return 0;
}