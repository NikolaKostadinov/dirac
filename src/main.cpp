#include <iostream>
#include "../include/basis.hpp"
#include "../include/vertex.h"

int main()
{
    Vertex<int> v;
    v.x = 0;
    v.y = 0;
    v.z = 0;

    Basis<float>* basis = new Basis<float>();

    std::cout << v.x << v.y << v.z << std::endl;
    std::cin.get();
    return 0;
}