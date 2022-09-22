#include <iostream>
#include "../include/dirac.h"

#define N 1000

int main()
{
    Vertex1<float> x[N];

    for (int i = 0; i < N; i++)
        x[i] = Vertex1<float>(i);

    Basis1<N> basis(x);

    std::cout << sizeof(x) << std::endl;
    std::cout << sizeof(basis) << std::endl;

    std::cin.get();
    return 0;
}