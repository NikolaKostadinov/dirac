#include <iostream>
#include "../include/dirac.h"

int main()
{
    Vertex1<float>* x0 = new Vertex1<float>();
    Vertex1<float>* x1 = new Vertex1<float>(1);
    Vertex1<float>* x2 = new Vertex1<float>(2);
    Vertex1<float>* x3 = new Vertex1<float>(3);
    Vertex1<float>* x[4] = { x0, x1, x2, x3 };

    Basis1<4> base();

    std::cin.get();
    return 0;
}