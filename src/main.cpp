#include <iostream>
#include "../include/dirac.h"

#define N 4

void vprint(Vertex1<float> v)
{
    std::cout << v.x << std::endl;
}

int main()
{
    Vertex1<float>* x = new Vertex1<float>[N];

    Basis1<N> basis(x);

    std::cin.get();
    return 0;
}