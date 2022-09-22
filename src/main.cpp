#include <iostream>
#include "../include/dirac.h"

#define NX 100
#define NY 10

int main()
{
    Vertex2<float> mesh[NX][NY];

    for (int i = 0; i < NX; i++)
        for (int j = 0; j < NY; j++)
            mesh[j][i] = Vertex2<float>(i, j);

    Basis2<NX, NY>* basis = new Basis2<NX, NY>;

    std::cout << sizeof(mesh) << std::endl;
    std::cout << sizeof(*basis) << std::endl;
    std::cout << sizeof(basis) << std::endl;

    std::cin.get();
    return 0;
}