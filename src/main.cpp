#include <iostream>
#include "../include/dirac.h"

#define N 10U

int main()
{
    Vertex3<float> xAxis[N];
    Vertex3<float> yAxis[N];
    Vertex3<float> zAxis[N];

    for (int i = 0; i < N; i++)
    {
        xAxis[i] = Vertex3<float>(i, 0, 0);
        yAxis[i] = Vertex3<float>(0, i, 0);
        zAxis[i] = Vertex3<float>(0, 0, i);
    }

    Basis3* toBasis = new Basis3(
        (Vertex3<float>*) &xAxis,
        (Vertex3<float>*) &yAxis,
        (Vertex3<float>*) &zAxis,
        N,
        N,
        N
    );

    Vertex3<float> myPoint = toBasis->yAxisAt(3);

    std::cout << myPoint.x << std::endl;
    std::cout << myPoint.y << std::endl;
    std::cout << myPoint.z << std::endl;

    return 0;
}