#include <iostream>
#include "../include/basis.hpp"

int main()
{
    Basis<float> basis;

    std::cout << sizeof(basis) << std::endl;
    std::cin.get();
    return 0;
}