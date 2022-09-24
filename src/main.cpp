#include <iostream>
#include "../include/dirac.h"

#define N 1000

int main()
{
    Vertex1<>* toOriginVertex = new Vertex1<>[N];
    Basis1<N>* toBasis = new Basis1<N>(toOriginVertex);

    return 0;
}