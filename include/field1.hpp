#pragma once

#include "basis1.hpp"

template <class T, unsigned int N>
class Field1
{
    public:

        Field1();
        ~Field1();

        Field1(Basis1<N> basis);
        Field1(Basis1<N>* basis);

    private:

        Basis1<N>* _basis;
        //T _values[N];
};