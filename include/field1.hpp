#pragma once

#include "basis1.hpp"

template <class T, unsigned int N>
class Field1
{
    public:

        Field1();
        virtual ~Field1();

        Field1(Basis1<N> basis);
        Field1(Basis1<N>* p_basis);

        void setValues(T values[N]);
        void setValues(T* p_values[N]);

        void getValue(T& reference, int index = 0);
        void getValue(T*& p_reference, int index = 0);

        T* getAddress(int index = 0);

    private:

        Basis1<N>* _basis;
        T _values[N];
};