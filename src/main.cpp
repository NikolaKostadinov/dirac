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

    for (int i = 0; i < N; i++)
        vprint(*x);

    Basis1<N> basis();

    std::cin.get();
    return 0;
}