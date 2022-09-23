#pragma once

#include "basis1.hpp"

template <class T, unsigned int N>
class Field1
{
    public:

        Field1();
        virtual ~Field1();

        Field1(Basis1<N> _basis_);
        Field1(Basis1<N>* _toBasis_);

        void setValues(T _values_[N]);
        void setValues(T* _toValues_[N]);

        void getValue(T& reference, int _index_ = 0);
        void getValue(T*& toReference, int _index_ = 0);

        T* address(int _index_ = 0);

    private:

        Basis1<N>* _toBasis;
        T _values[N];
};