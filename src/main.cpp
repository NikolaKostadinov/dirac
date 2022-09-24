#include <iostream>
#include "../include/dirac.h"

#define N 10U

int main()
{
    Vertex2<float> xVertices[N];
    Vertex2<float> yVertices[N];

    for (int i = 0; i < N; i++)
    {
        xVertices[i] = Vertex2<float>(i, 0);
        yVertices[i] = Vertex2<float>(0, i);
    }

    Basis2* toBasis = new Basis2(
        (Vertex2<float>*) &xVertices,
        (Vertex2<float>*) &yVertices,
        N,
        N
    );

    std::cout << toBasis->xAxisAt(3).y << std::endl;

    return 0;
}