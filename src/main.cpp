#include <iostream>
#include "../include/dirac.h"

#define N 10000

int main()
{
    float values[N];
    for (int i = 0; i < N; i++)
        values[i] = (float) i;
    
    Basis1<N>* basis = new Basis1<N>;
    Field1<float, N> field(basis);

    field.setValues(values);

    float f[N];
    float* p_origin = field.getAddress();
    
    for (int i = 0; i < N; i++)
    {
        f[i] = *p_origin;
        p_origin++;
    }

    for (int i = 0; i < N; i++)
        std::cout << f[i] << std::endl;

    std::cin.get();
    return 0;
}