#include <iostream>
#include "../include/dirac.h"

int main()
{
    Vertex<int> v0;
    Vertex<int> v1(1);
    Vertex<int> v2(2);
    Vertex<int> v3(3);

    std::vector<Vertex<int>> x = { v0, v1, v2, v3 };
    Line<int> line(x);

    Basis<int> basis(x);
    std::cout << basis.dimentions() << std::endl;

    std::cin.get();
    return 0;
}