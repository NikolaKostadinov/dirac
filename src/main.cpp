#include <iostream>
#include "../include/dirac.h"

#define N 10

int main()
{
    Vertex3<float> mesh[N][N][N];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                mesh[k][j][i] = Vertex3<float>(i, j, k);

    Basis3<N, N, N>* basis = new Basis3<N, N, N>(mesh);

    std::cout << sizeof(mesh) << std::endl;
    std::cout << sizeof(*basis) << std::endl;
    std::cout << sizeof(basis) << std::endl;

    std::cin.get();
    return 0;
}