#include <iostream>
#include "../include/dirac.h"

#define N 1000U

int main()
{
    Vertex1<float> vertices[N];
    for (int i = 0; i < N; i++)
        vertices[i] = Vertex1<float>(i * i);
    Basis1* toBasis = new Basis1((Vertex1<float>*) &vertices, N);

    std::cout << toBasis->vertex(13).x << std::endl;

    return 0;
}