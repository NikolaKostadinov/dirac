#include "../include/dirac.h"
#include <iostream>

#define N 3U
#define T 10000
#define DT 0.01F

int main()
{   
    Base* x = new Base(-1, N, 1);
    Basis2* basis = new Basis2(x, x);
    Field2<float>* f = new Field2<float>(basis);

    float arr[N][N] = { { 0, 1, 2 }, { 3, 4, 5 }, { 6, 7, 8 } };
    f->setValues(&arr[0][0]);

    std::cout << *f->address(0, 0) << std::endl;
    std::cout << *f->address(1, 0) << std::endl;
    std::cout << *f->address(2, 0) << std::endl;
    std::cout << *f->address(0, 1) << std::endl;
    std::cout << *f->address(1, 1) << std::endl;
    std::cout << *f->address(2, 1) << std::endl;
    std::cout << *f->address(0, 2) << std::endl;
    std::cout << *f->address(1, 2) << std::endl;
    std::cout << *f->address(2, 2) << std::endl;

    std::cin.get();
    return 0;
}