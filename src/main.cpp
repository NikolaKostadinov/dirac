#include <iostream>
#include "../include/dirac.h"

int main()
{
    std::vector<Vertex<int>> x = {
        Vertex<int>(),
        Vertex<int>(1),
        Vertex<int>(2),
        Vertex<int>(3),
        Vertex<int>(4),
        Vertex<int>(5),
        Vertex<int>(6)
    };

    Line<int> line(x);
    Basis<int> basis(line, line);
    std::cout << basis.dimentions() << std::endl;

    std::cout << sizeof(basis) << std::endl;

    std::cin.get();
    return 0;
}