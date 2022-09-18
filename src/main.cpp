#include <iostream>
#include "../include/basis.hpp"

int main()
{
    float x[2] = { 0, 1 };
    Basis<float> basis(x);

    std::cout << sizeof(basis) << std::endl;
    std::cin.get();
    return 0;
}