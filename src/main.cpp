#include <iostream>
#include "../include/dirac.h"

#define N 10000U

int main()
{   
    Base* x = new Base(-1.0F, 1.0F, 4U);
    Field1<float> f = Field1<float>(x);
    float values[4] = { 1.0F, 2.0F, 3.0F, 4.0F };
    f.setValues(values);

    std::cout << f.value(2) << std::endl;

    std::cin.get();
    return 0;
}