#include <iostream>
#include "../include/dirac.h"

int main()
{
    Vertex<int> v(1, 2, 3);
    Basis<float> basis;

    std::cout << v.x << v.y << v.z << std::endl;
    std::cin.get();
    return 0;
}