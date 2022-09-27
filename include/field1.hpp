#pragma once

#include "base.hpp"

template <class T>
class Field1
{
    public:

        Field1();
        virtual ~Field1();

        Field1(Base _basis_);
        Field1(Base* _toBasis_);

        unsigned int size();
        T* address(int _index_ = 0);

    private:

        Base* _basis;
        unsigned int _n;
        T* _toOriginValue;
};